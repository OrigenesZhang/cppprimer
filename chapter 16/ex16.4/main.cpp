#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename Iter, typename V>
Iter find(Iter begin, Iter end, V value) {
  for (; begin != end && *begin != value; ++begin);
  return begin;
}

int main() {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto vec_iter = find(vec.cbegin(), vec.cend(), 4);
  if (vec_iter == vec.cend())
    std::cout << "Not found in the vector" << std::endl;
  else
    std::cout << "Found in the vector" << std::endl;
  std::list<std::string> list{"abc", "de", "fgh"};
  auto list_iter = find(list.cbegin(), list.cend(), "ijk");
  if (list_iter == list.cend())
    std::cout << "Not found in the list" << std::endl;
  else
    std::cout << "Found in the list" << std::endl;
}
