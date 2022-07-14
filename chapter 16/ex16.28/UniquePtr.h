//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_28_UNIQUEPTR_H
#define EX16_28_UNIQUEPTR_H


#include <algorithm>
#include <cstddef>
#include "Delete.h"

template<typename, typename> class UniquePtr;
template<typename T, typename D>
void swap(UniquePtr<T, D>&, UniquePtr<T, D>&);

template<typename T, typename D = Delete>
class UniquePtr {
  friend void swap<T, D>(UniquePtr<T, D>&, UniquePtr<T, D>&);

public:
  UniquePtr() = default;
  explicit UniquePtr(T *raw_ptr): ptr(raw_ptr) {}

  UniquePtr(const UniquePtr&) = delete;
  UniquePtr& operator=(const UniquePtr&) = delete;
  UniquePtr(UniquePtr&& up) noexcept : ptr(up.ptr) { up.ptr = nullptr; }
  UniquePtr& operator=(UniquePtr&&) noexcept;
  ~UniquePtr() { deleter(ptr); }

  T& operator*() const { return *ptr; }
  T* operator->() const { return & this->operator*(); }
  operator bool() const { return ptr; }
  T* get() const noexcept { return ptr; }
  void swap(UniquePtr& lhs) { ::swap(*this, lhs); }

  T* release();
  void reset() noexcept { deleter(ptr); ptr = nullptr; }
  void reset(T* p) noexcept { deleter(ptr); ptr = p; }


private:
  T *ptr = nullptr;
  D deleter = D();
};

template<typename T, typename D>
void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs) {
  using std::swap;
  swap(lhs.ptr, rhs.ptr);
  swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>
UniquePtr<T, D> &UniquePtr<T, D>::operator=(UniquePtr<T, D> &&rhs) noexcept {
  if (this->ptr != rhs.ptr) {
    deleter(ptr);
    ptr = nullptr;
    ::swap(*this, rhs);
  }
  return *this;
}

template<typename T, typename D>
T *UniquePtr<T, D>::release() {
  T *ret = ptr;
  ptr = nullptr;
  return ret;
}


#endif //EX16_28_UNIQUEPTR_H
