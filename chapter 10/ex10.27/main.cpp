#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

int main() {
  std::vector<int> vec{1, 2, 1, 1, 2};
  std::list<int> list;
  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.cbegin(), vec.cend(), back_inserter(list));
  for (auto x : list)
    std::cout << x << ' ';
  std::cout << std::endl;
}
