#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "../ex12.19/str_blob.h"

bool StrBlobPtr::operator!=(const StrBlobPtr &rhs) const {
  return curr != rhs.curr;
}

int main() {
  std::ifstream ifs("input.in");
  StrBlob blob;
  std::string x;
  while (getline(ifs, x))
    blob.push_back(x);
  for (auto blob_ptr = blob.begin(); blob_ptr != blob.end(); blob_ptr.incr())
    std::cout << blob_ptr.deref() << std::endl;
}
