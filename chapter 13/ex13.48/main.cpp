#include "../ex13.47/String.h"
#include <vector>

int main() {
  std::vector<String> vec;
  String s0, s1("abc");
  vec.push_back(s0);
  vec.push_back(s1);
  return 0;
}
