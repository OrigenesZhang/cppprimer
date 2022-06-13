#include <iostream>
#include <vector>

std::vector<int> *allocate() {
  return new std::vector<int>();
}

void input(std::vector<int> *vec) {
  int x;
  while (std::cin >> x)
    vec->push_back(x);
}

void print(const std::vector<int> *vec) {
  for (auto x : *vec)
    std::cout << x << ' ';
  std::cout << std::endl;
}

int main() {
  auto ptr = allocate();
  input(ptr);
  print(ptr);
  delete ptr;
  ptr = nullptr;
}
