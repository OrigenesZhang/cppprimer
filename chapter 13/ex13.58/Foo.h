//
// Created by Bin Zhang on 26/6/22.
//

#ifndef EX13_58_FOO_H
#define EX13_58_FOO_H

#include <vector>

class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;
private:
  std::vector<int> data;
};


#endif //EX13_58_FOO_H
