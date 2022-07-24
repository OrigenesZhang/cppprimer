#include <iostream>
#include <vector>
#include <bitset>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 8, 13, 21};
  std::bitset<32> bs1;
  for (auto x : vec)
    bs1.set(x);
  std::bitset<32> bs2;
  bs2 = bs1;
  std::cout << bs1 << std::endl;
  std::cout << bs2 << std::endl;
}
