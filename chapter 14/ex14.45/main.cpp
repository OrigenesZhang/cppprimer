#include <iostream>
#include <string>
#include "Sales_data.h"

int main() {
  Sales_data cpp_primer("C++ Primer", 4, 128);
  std::cout << cpp_primer << std::endl;
  std::cout << static_cast<std::string>(cpp_primer) << std::endl;
  std::cout << static_cast<double>(cpp_primer) << std::endl;
}
