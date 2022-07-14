#include <iostream>
#include <string>
#include "Blob.h"
#include "BlobPtr.h"

int main() {
  Blob<std::string> a = {"hi", "bye", "now"};
  BlobPtr<std::string> p(a);
  *p = "okay";
  std::cout << p->size() << std::endl;
}
