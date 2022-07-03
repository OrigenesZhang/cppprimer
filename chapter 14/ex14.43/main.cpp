#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main() {
  std::vector<int> vec{2, 3, 4, 5, 6, 7};
  int input;
  std::cin >> input;
  std::modulus<> mod;
  auto is_divisible = std::any_of(vec.cbegin(), vec.cend(), [input, &mod](int x) {
    return mod(input, x) == 0;
  });
  std::cout << (is_divisible ? "Yes" : "No") << std::endl;
}
