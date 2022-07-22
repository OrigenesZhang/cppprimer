#include <iostream>
#include <vector>
#include <string>

template <typename T>
size_t count(const std::vector<T> &vec, T value) {
  size_t count = 0;
  for (const auto &elem : vec)
    if (elem == value)
      count++;
  return count;
}

int main() {
  std::vector<int> ivec{1, 2, 1, 2, 3, 4, 1, 1, 2};
  std::cout << count(ivec, 1) << std::endl;

  std::vector<std::string> svec{"abc", "k", "pe", "abc"};
  std::cout << count(svec, std::string("abc")) << std::endl;
}
