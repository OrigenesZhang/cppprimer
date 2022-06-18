#include <iostream>
#include "Employee.h"

int Employee::counter = 10;

int main() {
  Employee a, b("abc");
  std::cout << b.get_id() << std::endl;
}
