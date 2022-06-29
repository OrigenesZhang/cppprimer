#include <iostream>
#include "StrVec.h"

int main() {
  StrVec v;
  v = {"a", "b", "abc"};
  for (const auto &s : v)
    std::cout << s << ' ';
  std::cout << std::endl;
}