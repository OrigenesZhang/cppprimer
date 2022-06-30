//
// Created by Bin Zhang on 1/7/22.
//

#ifndef EX14_26_STRING_H
#define EX14_26_STRING_H

#include <iostream>
#include <memory>
#include <utility>

class String {
public:
  String() : String("") {}
  String(const char*);
  String(const String&);
  String& operator=(const String&);
  char& operator[](size_t n) { return elements[n]; }
  const char& operator[](size_t n) const { return elements[n]; }
  ~String();

  [[nodiscard]] const char *c_str() const { return elements; }
  [[nodiscard]] size_t size() const { return cap - elements - 1; }
  [[nodiscard]] const char *begin() const { return elements; }
  [[nodiscard]] const char *end() const { return cap; }
private:
  static std::allocator<char> alloc;
  static std::pair<char*, char*> alloc_n_copy(const char*, const char*);
  void range_initialize(const char*, const char*);
  void free();
  char *elements;
  char *cap;
};

std::ostream& operator<<(std::ostream&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

#endif //EX14_26_STRING_H
