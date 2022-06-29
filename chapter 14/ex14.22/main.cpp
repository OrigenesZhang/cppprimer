#include <iostream>
#include "Sales_data.h"

int main() {
  std::string s = "abcde";
  Sales_data x;
  x = s;
  std::cout << x << std::endl;
}
