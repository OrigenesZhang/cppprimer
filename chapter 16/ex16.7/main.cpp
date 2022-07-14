#include <iostream>
#include <string>

template <typename T, size_t N>
constexpr size_t get_size(const T(&)[N]) {
  return N;
}

int main() {
  std::string x[] = {"x", "zy"};
  std::cout << get_size(x) << std::endl;
}
