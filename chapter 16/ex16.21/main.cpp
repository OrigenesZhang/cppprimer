#include "DebugDelete.h"

int main() {
  auto *p = new double;
  DebugDelete d(std::cout);
  d(p);
  int *ip = new int;
  DebugDelete()(ip);
}
