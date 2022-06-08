#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit)
    std::cout << *rit << ' ';
  std::cout << std::endl;
}
