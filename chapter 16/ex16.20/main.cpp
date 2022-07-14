#include <iostream>
#include <vector>

template <typename T> std::ostream &print(std::ostream &os, const T& container) {
  for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    os << *iter << " ";
  return os;
}

int main() {
  std::vector<int> vec{0, 1, 2, 3};
  print(std::cout, vec);
}
