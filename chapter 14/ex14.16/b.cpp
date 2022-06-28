#include <iostream>
#include "StrVec.h"

int main() {
  StrVec v1, v2;
  v1.push_back("abc");
  v2.push_back("abc");
  std::cout << (v1 == v2) << std::endl;
  v1.push_back("def");
  v2.push_back("de");
  std::cout << (v1 != v2) << std::endl;
}
