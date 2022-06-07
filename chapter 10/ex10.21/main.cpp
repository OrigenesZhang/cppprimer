#include <iostream>

int main() {
  int x = 3;
  // C++11: the return type of closure's operator() was only
  // deduced if lambda body contains a single return
  // C++14 onwards: deduced as if for C++14
  // auto-returning function
  auto dec_to_zero = [&x]() {
    if (x == 0) return false;
    x--;
    return true;
  };
  while (dec_to_zero())
    std::cout << x << std::endl;
}
