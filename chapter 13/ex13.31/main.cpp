#include <vector>
#include <algorithm>
#include "HasPtr.h"

int main() {
  HasPtr a{"a"}, b{"b"}, ab{"ab"};
  std::vector<HasPtr> vec{a, b, ab};
  std::sort(vec.begin(), vec.end());
  for (const auto &x : vec)
    x.print();
}
