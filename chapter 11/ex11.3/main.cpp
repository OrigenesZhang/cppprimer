#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, size_t> word_count;
  std::string word;
  while (std::cin >> word)
    word_count[word]++;
  for (const auto &[k, v] : word_count)
    std::cout << "Word " << k << " occurs "
    << v << " time" << (v == 1 ? "" : "s") << std::endl;
}
