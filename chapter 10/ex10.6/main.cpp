#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 4, 5};
  std::fill_n(vec.begin(), vec.size(), 0);
  for (auto x : vec) std::cout << x << ' ';
  std::cout << std::endl;
}
