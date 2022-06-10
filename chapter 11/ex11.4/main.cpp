#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

int main() {
  std::map<std::string, size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    for (auto &ch : word)
      ch = tolower(ch);
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    word_count[word]++;
  }
  for (const auto &[k, v] : word_count)
    std::cout << "Word " << k << " occurs "
    << v << " time" << (v == 1 ? "" : "s") << std::endl;
}
