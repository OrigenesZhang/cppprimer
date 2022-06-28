#include <iostream>
#include "String.h"

int main() {
  String s1("Hey there"), s2("Not the same");
  if (s1 < s2)
    std::cout << s1 << std::endl;
}
