#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;

bool fiveCharsOrMore(const string &s) {
  return s.size() >= 5;
}

int main() {
  std::vector<string> vec{"a", "aaaa", "aaaaa", "aa", "aaaaaa"};
  auto end_iter = std::partition(vec.begin(), vec.end(), fiveCharsOrMore);
  for (auto iter = vec.cbegin(); iter != end_iter; ++iter)
    std::cout << *iter << ' ';
  std::cout << std::endl;
  return 0;
}
