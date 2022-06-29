//
// Created by Bin Zhang on 29/6/22.
//

#include "StrVec.h"
#include <algorithm>

// statics must be defined in cpp files
std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

// Clang-Tidy: Method 'alloc_n_copy' can be made static
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements; )
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(const StrVec &s) {
  auto new_data = alloc_n_copy(s.begin(), s.end());
  elements = new_data.first;
  first_free = cap = new_data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

StrVec::~StrVec() {
  free();
}

void StrVec::reallocate() {
  auto new_cap = size() ? 2 * size() : 1;
  alloc_n_move(new_cap);
}

void StrVec::alloc_n_move(size_t new_cap) {
  auto new_data = alloc.allocate(new_cap);
  auto dest = new_data;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = new_data;
  first_free = dest;
  cap = elements + new_cap;
}

void StrVec::reserve(size_t new_cap) {
  if (new_cap <= capacity())
    return;
  alloc_n_move(new_cap);
}

void StrVec::resize(size_t new_size) {
  resize(new_size, std::string());
}

void StrVec::resize(size_t new_size, const std::string &s) {
  if (new_size > size()) {
    if (new_size > capacity())
      reserve(2 * new_size);
    for (size_t i = size(); i != new_size; ++i)
      alloc.construct(first_free++, s);
  } else if (new_size < size()) {
    while (first_free != elements + new_size)
      alloc.destroy(--first_free);
  }
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
  s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
  auto data = alloc_n_copy(il.begin(), il.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
  return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
  return !(lhs < rhs);
}