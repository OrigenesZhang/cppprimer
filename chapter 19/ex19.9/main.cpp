#include <iostream>
#include <typeinfo>
#include <string>

class Base {};

class Derived : public Base {};

int main() {
  int arr[10];
  Derived d;
  Base *p = &d;
  std::cout << typeid(42).name() << ", "
            << typeid(arr).name() << ", "
            << typeid(std::string).name() << ", "
            << typeid(p).name() << ", "
            << typeid(*p).name() << std::endl;
}
