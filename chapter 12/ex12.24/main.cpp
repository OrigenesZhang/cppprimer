#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  char *s = new char[size + 1]();
  std::cin.ignore();
  std::cin.get(s, size + 1);
  std::cout << s;
  delete [] s;
}
