#include <fstream>
#include <vector>
#include <memory>

void exercise(int *b, int *e) {
  std::vector<int> v(b, e);
  std::shared_ptr<int> p(new int[v.size()], [](int *p) { delete[] p; });
  std::ifstream in("ints");
  // exception occurs here
}

int main() {}
