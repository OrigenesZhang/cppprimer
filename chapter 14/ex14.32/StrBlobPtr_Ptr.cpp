//
// Created by Bin Zhang on 2/7/22.
//

#include "StrBlobPtr_Ptr.h"

StrBlobPtr &StrBlobPtr_Ptr::operator*() const {
  return *ptr;
}

StrBlobPtr *StrBlobPtr_Ptr::operator->() const {
  return ptr;
}
