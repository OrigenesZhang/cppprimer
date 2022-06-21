//
// Created by Bin Zhang on 22/6/22.
//

#ifndef EX13_31_HASPTR_H
#define EX13_31_HASPTR_H


#include <string>
#include <iostream>

class HasPtr {
public:
  friend void swap(HasPtr&, HasPtr&);
  friend bool operator<(const HasPtr&, const HasPtr&);
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  HasPtr& operator=(HasPtr rhs) {
    this->swap(rhs);
    return *this;
  }
  void swap(HasPtr &rhs) {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
    std::cout << "swap(HasPtr&)" << std::endl;
  }
  ~HasPtr() { delete ps; }
  void print() const { std::cout << *ps << std::endl; }
private:
  std::string *ps;
  int i;
};

#endif //EX13_31_HASPTR_H
