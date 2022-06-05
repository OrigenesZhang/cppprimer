#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> vec;
  int x, target;
  std::cin >> target;
  while (std::cin >> x) {
    vec.push_back(x);
  }
  std::cout << std::count(vec.begin(), vec.end(), target) << std::endl;
  return 0;
}
