//
// Created by Bin Zhang on 27/6/22.
//

#ifndef EX14_7_STRING_H
#define EX14_7_STRING_H


#include <iostream>
#include <memory>
#include <utility>

class String {
public:
  String() : String("") {}
  String(const char*);
  String(const String&);
  String& operator=(const String&);
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


#endif //EX14_7_STRING_H
