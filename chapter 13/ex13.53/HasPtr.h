//
// Created by Bin Zhang on 26/6/22.
//

#ifndef EX13_53_HASPTR_H
#define EX13_53_HASPTR_H


#include <string>

class HasPtr {
public:
  friend void swap(HasPtr&, HasPtr&);
  HasPtr(const std::string &s = std::string());
  HasPtr(const HasPtr&);
  HasPtr(HasPtr&&) noexcept;
  HasPtr &operator=(HasPtr);
//  HasPtr &operator=(const HasPtr&);
//  HasPtr &operator=(HasPtr&&) noexcept;
  ~HasPtr();
private:
  std::string *ps;
  int i;
};


#endif //EX13_53_HASPTR_H
