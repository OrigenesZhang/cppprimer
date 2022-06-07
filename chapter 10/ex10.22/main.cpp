#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::placeholders::_1;

bool lessThanOrEqualToXChars(const string &s, string::size_type sz) {
  return s.size() <= sz;
}

int main() {
  std::vector<string> vec{"abc", "1234567", "abcdefgh", "1234"};
  std::cout << std::count_if(vec.cbegin(), vec.cend(), std::bind(lessThanOrEqualToXChars, _1, 6)) << std::endl;
  return 0;
}