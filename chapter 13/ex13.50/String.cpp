//
// Created by Bin Zhang on 26/6/22.
//

#include "String.h"
#include <algorithm>
#include <iostream>

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
  std::cout << "copy constructor" << std::endl;
}

String &String::operator=(const String &rhs) {
  auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  std::tie(elements, cap) = new_data;
  std::cout << "copy assignment" << std::endl;
  return *this;
}

String::String(String &&s) noexcept : elements(s.elements), cap(s.cap) {
  s.elements = s.cap = nullptr;
  std::cout << "move constructor" << std::endl;
}

String &String::operator=(String &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    cap = rhs.cap;
    rhs.elements = rhs.cap = nullptr;
  }
  std::cout << "move assignment" << std::endl;
  return *this;
}