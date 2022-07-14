#include <iostream>
#include "Screen.h"

int main() {
  Screen<4, 5> s;
  std::cin >> s;
  s.move(1, 2);
  s.set('X');
  s.set(2, 3, 'c');
  std::cout << s << std::endl;
}
