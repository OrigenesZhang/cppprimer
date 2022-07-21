#include <iostream>

template <typename T>
std::ostream &print(std::ostream &os, const T &t) {
  return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest) {
  os << t << " ";
  return print(os, rest...);
}

int main() {
  print(std::cout, 1);
  std::cout << std::endl;
  print(std::cout, "two", 1);
  std::cout << std::endl;
  print(std::cout, 1, 0.1, "three", "four", 5);
  std::cout << std::endl;
}
