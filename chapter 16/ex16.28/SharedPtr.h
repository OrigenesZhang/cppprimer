//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_28_SHAREDPTR_H
#define EX16_28_SHAREDPTR_H


#include <algorithm>
#include <cstddef>
#include "Delete.h"

template<typename T> class SharedPtr;
template<typename T>
void swap(SharedPtr<T>&, SharedPtr<T>&);

template<typename T>
class SharedPtr {
  friend void swap<T>(SharedPtr<T>&, SharedPtr<T>&);

public:
  SharedPtr(): ptr(nullptr), ref_count(new size_t(1)), deleter(Delete()) {}
  explicit SharedPtr(T *raw_ptr): ptr(raw_ptr), ref_count(new size_t(1)), deleter(Delete()) {}

  SharedPtr(const SharedPtr& sp): ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter) { ++*ref_count; }
  SharedPtr& operator=(const SharedPtr&);
  SharedPtr(SharedPtr &&sp) noexcept : ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter) {
    sp.ptr = nullptr;
    sp.ref_count = nullptr;
  }
  SharedPtr& operator=(SharedPtr&&) noexcept;
  ~SharedPtr() { dealloc(); }

  T& operator*() const { return *ptr; }
  T* operator->() const { return & this->operator*(); }
  operator bool() const { return ptr; }
  T* get() const noexcept { return ptr; }
  void swap(SharedPtr& lhs) { ::swap(*this, lhs); }
  [[nodiscard]] size_t use_count() const { return *ref_count; }

  void reset() { dealloc(); }
  void reset(T* p) {
    if (p != ptr) {
      dealloc();
      ptr = p;
      ref_count = new size_t(1);
    }
  }
  void reset(T *p, const Delete &d) {
    reset(p);
    deleter = d;
  }

private:
  T *ptr;
  size_t *ref_count;
  Delete deleter;

  void dealloc();
};

template<typename T>
void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
  using std::swap;
  swap(lhs.ptr, rhs.ptr);
  swap(lhs.ref_count, rhs.ref_count);
  swap(lhs.deleter, rhs.deleter);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &rhs) {
  ++*rhs.ref_count;
  dealloc();
  ptr = rhs.ptr;
  ref_count = rhs.ref_count;
  deleter = rhs.deleter;
  return *this;
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> &&rhs) noexcept {
  swap(*this, rhs);
  rhs.dealloc();
  return *this;
}

template<typename T>
void SharedPtr<T>::dealloc() {
  if (ptr && --*ref_count == 0) {
    delete ref_count;
    deleter(ptr);
  } else if (!ptr && ref_count) {
    delete ref_count;
  }
  ptr = nullptr;
  ref_count = nullptr;
}


#endif //EX16_28_SHAREDPTR_H
