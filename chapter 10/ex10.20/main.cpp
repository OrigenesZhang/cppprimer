#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;

int main() {
  std::vector<string> vec{"abc", "1234567", "abcdefgh", "1234"};
  std::cout << std::count_if(vec.cbegin(), vec.cend(), [](const string &s) {
    return s.size() > 6;
  }) << std::endl;
  return 0;
}
