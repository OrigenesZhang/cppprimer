//
// Created by Bin Zhang on 2/7/22.
//

#ifndef EX14_32_STRBLOBPTR_PTR_H
#define EX14_32_STRBLOBPTR_PTR_H

#include "../ex14.30/StrBlob.h"

class StrBlobPtr_Ptr {
public:
  StrBlobPtr_Ptr() = default;
  StrBlobPtr_Ptr(StrBlobPtr *p) : ptr(p) {}
  StrBlobPtr& operator*() const;
  StrBlobPtr* operator->() const;
private:
  StrBlobPtr *ptr = nullptr;
};


#endif //EX14_32_STRBLOBPTR_PTR_H
