//
// Created by Bin Zhang on 26/6/22.
//

#include "Foo.h"
#include <algorithm>
#include <iostream>

Foo Foo::sorted() &&{
  std::cout << "Foo Foo::sorted() &&" << std::endl;
  std::sort(data.begin(), data.end());
  return *this;
}

Foo Foo::sorted() const &{
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  return Foo(*this).sorted();
}
