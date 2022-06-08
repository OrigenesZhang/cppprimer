#include <iostream>
#include <list>
#include <algorithm>

int main() {
  std::list<int> list{1, 2, 3, 0, 4, 5, 6, 7, 0, 8, 9};
  auto last_zero = std::find(list.crbegin(), list.crend(), 0);
  std::cout << std::distance(last_zero, list.crend()) << std::endl;
}
