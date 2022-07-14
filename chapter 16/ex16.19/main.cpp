#include <iostream>
#include <vector>

template <typename T> std::ostream &print(std::ostream &os, const T& container) {
  for (typename T::size_type i = 0; i != container.size(); ++i)
    os << container[i] << " ";
  return os;
}

int main() {
  std::vector<int> vec{0, 1, 2, 3};
  print(std::cout, vec);
}
