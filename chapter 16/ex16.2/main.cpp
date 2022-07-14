#include <iostream>
#include <functional>

template <typename T>
int compare(const T& v1, const T& v2) {
  if (std::less<>()(v1, v2)) return -1;
  if (std::less<>()(v2, v1)) return 1;
  return 0;
}

int main() {
  int x = 3, y = 5;
  std::cout << compare(x, y) << std::endl;
  std::string s = "xyz", t = "abc";
  std::cout << compare(s, t) << std::endl;
}
