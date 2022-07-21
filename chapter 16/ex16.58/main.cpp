#include <iostream>
#include <string>
#include <vector>
#include "Vec.h"

int main() {
  Vec<std::string> str_vec;
  str_vec.emplace_back("abc");
  for (const auto &s : str_vec)
    std::cout << s << " ";
  std::cout << std::endl;

  Vec<std::vector<int>> vec_vec;
  vec_vec.emplace_back(3, 2);
  vec_vec.emplace_back(1, 1);
  for (const auto &vec : vec_vec) {
    for (auto x : vec)
      std::cout << x << " ";
    std::cout << std::endl;
  }
}
