//
// Created by Bin Zhang on 22/6/22.
//

#include "HasPtr.h"

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
  return *lhs.ps < *rhs.ps;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
  lhs.swap(rhs);
}
