//
// Created by Bin Zhang on 19/6/22.
//

#ifndef EX13_27_HASPTR_H
#define EX13_27_HASPTR_H

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use_count(new size_t(1)) {}
  HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i), use_count(hp.use_count) {
    (*use_count)++;
  }
  HasPtr& operator=(const HasPtr &rhs) {
    (*rhs.use_count)++;
    if (--*use_count == 0) {
      delete ps;
      delete use_count;
    }
    ps = rhs.ps;
    use_count = rhs.use_count;
    i = rhs.i;
    return *this;
  }
  ~HasPtr() {
    if (--*use_count == 0) {
      delete ps;
      delete use_count;
    }
  }
private:
  std::string *ps;
  int i;
  size_t *use_count;
};

#endif //EX13_27_HASPTR_H
