#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::vector<int> vec{1, 2, 4, 3, 1, 2};
  int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
  std::cout << sum << std::endl;
  return 0;
}
