#include "str_blob.h"

ConstStrBlobPtr StrBlob::begin() const {
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr(*this, data->size());
}

int main() {}
