#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual {
public:
  explicit IsEqual(int v): value(v) {}
  bool operator()(int v) const {
    return v == value;
  }
private:
  int value;
};

int main() {
  std::vector<int> vec{1, 2, 3, 2, 1, 2, 3};
  std::replace_if(vec.begin(), vec.end(), IsEqual(2), 4);
  for (auto x : vec)
    std::cout << x << ' ';
  std::cout << std::endl;
}
