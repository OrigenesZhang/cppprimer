#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

void elemDups(vector<string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto end_iter = std::unique(vec.begin(), vec.end());
  vec.erase(end_iter, vec.end());
}

bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

int main() {
  std::vector<std::string> vec{"a", "c", "b", "a", "b", "aa", "aa"};
  elemDups(vec);
  std::stable_sort(vec.begin(), vec.end(), isShorter);
  for (const auto &x : vec) std::cout << x << ' ';
  std::cout << std::endl;
}
