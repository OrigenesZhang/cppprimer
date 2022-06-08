#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto it = std::prev(vec.cend()); ; --it) {
    std::cout << *it << ' ';
    if (it == vec.cbegin()) break;
  }
  std::cout << std::endl;
}
