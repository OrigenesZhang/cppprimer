//
// Created by Bin Zhang on 29/6/22.
//

#include "String.h"
#include <algorithm>

std::allocator<char> String::alloc;

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void String::range_initialize(const char *b, const char *e) {
  std::tie(elements, cap) = alloc_n_copy(b, e);
}

void String::free() {
  if (elements) {
    std::for_each(elements, cap, [](char &c) { alloc.destroy(&c); });
    alloc.deallocate(elements, cap - elements);
  }
}

String::~String() {
  free();
}

String::String(const char *s) {
  size_t size = 0;
  while (*(s + size)) size++;
  range_initialize(s, s + size + 1);
}

String::String(const String &s) {
  range_initialize(s.begin(), s.end());
}

String &String::operator=(const String &rhs) {
  auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  std::tie(elements, cap) = new_data;
  return *this;
}

bool operator==(const String &lhs, const String &rhs) {
  return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs) {
  return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs) {
  return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
  return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream &os, const String &s) {
  os << s.c_str();
  return os;
}
