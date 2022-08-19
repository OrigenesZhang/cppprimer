#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::string> svec{"abc", "", "", "ab", "", "xyz"};
  std::cout << std::count_if(svec.cbegin(), svec.cend(), std::mem_fn(&std::string::empty)) << std::endl;
}
