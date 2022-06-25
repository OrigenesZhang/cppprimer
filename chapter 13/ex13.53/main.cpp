#include "HasPtr.h"

int main() {
  HasPtr hp1("abc"), hp2("def"), *hp_ptr = new HasPtr("ptr");
  hp1 = hp2;
  hp1 = std::move(*hp_ptr);
}
