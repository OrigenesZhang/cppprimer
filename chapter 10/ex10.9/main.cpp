#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void elemDups(std::vector<std::string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto end_iter = std::unique(vec.begin(), vec.end());
  vec.erase(end_iter, vec.end());
}

int main() {
  std::vector<std::string> vec{"a", "b", "c", "a", "b"};
  elemDups(vec);
  for (const auto &x : vec) std::cout << x << ' ';
  std::cout << std::endl;
}
