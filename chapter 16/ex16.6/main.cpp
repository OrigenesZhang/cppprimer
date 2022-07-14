#include <iostream>

template <typename T, size_t N>
const T* begin(const T (&a)[N]) {
  return a;
}

template <typename T, size_t N>
const T* end(const T (&a)[N]) {
  return a + N;
}

int main() {
  int x[] = {0, 1, 2, 3, 4, 5};
  for (auto p = begin(x); p != end(x); ++p)
    std::cout << *p << " ";
  std::cout << std::endl;
}
