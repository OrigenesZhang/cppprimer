#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
  return s.size() >= sz;
}

int main() {
  std::vector<int> vec{1, 3, 4, 5, 2, 7, 6};
  string bench = "123456";
  auto iter = std::find_if_not(vec.cbegin(), vec.cend(), std::bind(check_size, bench, _1));
  if (iter == vec.cend())
    std::cout << "Not found" << std::endl;
  else
    std::cout << *iter << std::endl;
  return 0;
}
