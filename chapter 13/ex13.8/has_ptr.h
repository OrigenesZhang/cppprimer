//
// Created by Bin Zhang on 18/6/22.
//

#ifndef EX13_8_HAS_PTR_H
#define EX13_8_HAS_PTR_H

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  HasPtr& operator=(const HasPtr &rhs) {
    if (this != &rhs) {
      delete ps;
      ps = new std::string(*rhs.ps);
      i = rhs.i;
    }
    return *this;
  }
private:
  std::string *ps;
  int i;
};

#endif //EX13_8_HAS_PTR_H
