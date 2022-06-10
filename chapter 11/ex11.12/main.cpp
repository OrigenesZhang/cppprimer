#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
  std::string s;
  int i;
  std::vector<std::pair<std::string, int>> vec;
  while (std::cin >> s >> i)
    vec.emplace_back(s, i);
  for (const auto &p : vec)
    std::cout << p.first << ' ' << p.second << std::endl;
}
