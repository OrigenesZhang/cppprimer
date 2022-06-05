#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;

int main() {
  std::vector<string> vec;
  string x, target;
  std::cin >> target;
  while (std::cin >> x) {
    vec.push_back(x);
  }
  std::cout << std::count(vec.begin(), vec.end(), target) << std::endl;
  return 0;
}
