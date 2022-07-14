#include <iostream>
#include <string>
#include "Vec.h"

int main() {
  Vec<std::string> vec;
  vec.push_back("abc");
  std::string s;
  std::cin >> s;
  vec.push_back(s);
  std::cout << vec.size() << std::endl;
  for (const auto &t : vec)
    std::cout << t << " ";
  std::cout << std::endl;
}
