#include <iostream>
#include <vector>
#include <string>
#include <cstring>

template <typename T>
size_t count(const std::vector<T> &vec, T value) {
  size_t count = 0;
  for (const auto &elem : vec)
    if (elem == value)
      count++;
  return count;
}

template <>
size_t count(const std::vector<const char*> &vec, const char *value) {
  size_t count = 0;
  for (const auto &elem : vec)
    if (strcmp(elem, value) == 0)
      count++;
  return count;
}

int main() {
  std::vector<int> ivec{1, 2, 1, 2, 3, 4, 1, 1, 2};
  std::cout << count(ivec, 1) << std::endl;

  std::vector<std::string> svec{"abc", "k", "pe", "abc"};
  std::cout << count(svec, std::string("abc")) << std::endl;

  std::vector<const char*> cc_vec{"abc", "k", "pe", "abc"};
  std::cout << count(cc_vec, "abc") << std::endl;
}
