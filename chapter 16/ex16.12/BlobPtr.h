//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_12_BLOBPTR_H
#define EX16_12_BLOBPTR_H


#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "Blob.h"

template <typename> class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr {
  friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
  BlobPtr(): curr(0) {}
  BlobPtr(Blob<T>& b, size_t sz = 0): wptr(b.data), curr(sz) {}

  T& operator*() const;
  T* operator->() const;
  BlobPtr& operator++();
  BlobPtr& operator--();
  BlobPtr operator++(int);
  BlobPtr operator--(int);

private:
  std::shared_ptr<std::vector<T>> check(size_t, const std::string&) const;
  std::weak_ptr<std::vector<T>> wptr;
  size_t curr;
};

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound BlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

template<typename T>
T &BlobPtr<T>::operator*() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

template<typename T>
T *BlobPtr<T>::operator->() const {
  return & this->operator*();
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
  check(curr, "increment past end of BlobPtr");
  ++curr;
  return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
  curr--;
  check(curr, "decrement past begin of BlobPtr");
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
  if (lhs.wptr.lock() != rhs.wptr.lock())
    throw std::runtime_error("BlobPtrs to different Blobs");
  return lhs.i == rhs.i;
}


#endif //EX16_12_BLOBPTR_H
