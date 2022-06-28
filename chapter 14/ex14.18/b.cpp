#include <iostream>
#include "StrVec.h"

int main() {
  StrVec v1, v2;
  v1.push_back("a"); v1.push_back("a");
  v2.push_back("a"); v2.push_back("b");
  if (v1 < v2) {
    for (const auto &s : v1)
      std::cout << s << ' ';
    std::cout << std::endl;
  }
}