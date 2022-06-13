#include <iostream>
#include <memory>
#include <vector>

auto allocate() {
  return std::make_shared<std::vector<int>>();
}

void input(const std::shared_ptr<std::vector<int>> &vec) {
  int x;
  while (std::cin >> x)
    vec->push_back(x);
}

void print(const std::shared_ptr<std::vector<int>> &vec) {
  for (auto x : *vec)
    std::cout << x << ' ';
  std::cout << std::endl;
}

int main() {
  auto ptr = allocate();
  input(ptr);
  print(ptr);
}
