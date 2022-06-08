#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::copy;

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> list1, list2, list3;
  copy(vec.cbegin(), vec.cend(), back_inserter(list1));
  copy(vec.cbegin(), vec.cend(), inserter(list2, list2.begin()));
  copy(vec.cbegin(), vec.cend(), front_inserter(list3));
  auto print_list = [](const std::list<int> &list) {
    for (auto x : list)
      std::cout << x << ' ';
    std::cout << std::endl;
  };
  // seq
  print_list(list1);
  // seq
  print_list(list2);
  // rev
  print_list(list3);
}
