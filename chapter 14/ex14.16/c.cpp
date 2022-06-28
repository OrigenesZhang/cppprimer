#include <iostream>
#include "String.h"

int main() {
  String s1("Hey there"), s2("Not the same");
  std::cout << (s1 == s2) << std::endl;
}
