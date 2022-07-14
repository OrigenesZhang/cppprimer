#include <iostream>
#include <string>

template <typename T, size_t N>
void print(const T (&a)[N]) {
  for (size_t i = 0; i != N; ++i)
    std::cout << a[i] << " ";
  std::cout << std::endl;
}

int main() {
  int x[5] = {1, 2, 2};
  print(x);
  std::string y[] = {"abc", "exy", "yzx"};
  print(y);
}
