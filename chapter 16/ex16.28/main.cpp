#include <iostream>
#include "SharedPtr.h"
#include "UniquePtr.h"

int main() {
  auto p1 = SharedPtr<int>(new int(1));
  auto p2(p1);
  std::cout << *p2 << std::endl;
  std::cout << p1.use_count() << std::endl;

  auto up1 = UniquePtr<double>(new double(0.5));
  auto up2 = std::move(up1);
  std::cout << *up2 << std::endl;
}
