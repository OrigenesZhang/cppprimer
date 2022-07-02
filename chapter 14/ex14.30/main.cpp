#include <iostream>
#include "StrBlob.h"

int main() {
  StrBlob a1 = {"hi", "bye", "now"};
  StrBlobPtr p(a1);
  ConstStrBlobPtr cp(a1, 1);
  *p = "okay";
  std::cout << p->size() << std::endl;
  std::cout << cp->size() << std::endl;
}
