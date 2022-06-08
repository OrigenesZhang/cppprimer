#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> list(5);
  std::copy(vec.cbegin() + 3, vec.cbegin() + 8, list.rbegin());
  for (auto x : list)
    std::cout << x << ' ';
  std::cout << std::endl;
}
