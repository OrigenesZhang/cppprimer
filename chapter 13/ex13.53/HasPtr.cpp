//
// Created by Bin Zhang on 26/6/22.
//

#include "HasPtr.h"
#include <iostream>

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) {
  std::cout << "constructor" << std::endl;
}

HasPtr::HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {
  std::cout << "copy constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr &&hp) noexcept : ps(hp.ps), i(hp.i) {
  hp.i = 0;
  std::cout << "move constructor" << std::endl;
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
  swap(*this, rhs);
  return *this;
}

HasPtr::~HasPtr() {
  std::cout << "destructor" << std::endl;
  delete ps;
}

//HasPtr &HasPtr::operator=(const HasPtr &rhs) {
//  if (this != &rhs) {
//    ps = new std::string(*rhs.ps);
//    i = rhs.i;
//  }
//  std::cout << "copy assignment" << std::endl;
//  return *this;
//}
//
//HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
//  if (this != &rhs) {
//    ps = rhs.ps;
//    i = rhs.i;
//  }
//  std::cout << "move assignment" << std::endl;
//  return *this;
//}
