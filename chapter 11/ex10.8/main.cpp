#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::string> exclude{"the", "but", "and", "or", "an", "a"};
  std::sort(exclude.begin(), exclude.end());
  std::string word;
  while (std::cin >> word) {
    bool is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
    if (is_excluded)
      std::cout << "excluded" << std::endl;
    else
      std::cout << "included" << std::endl;
  }
}
