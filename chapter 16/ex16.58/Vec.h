//
// Created by Bin Zhang on 22/7/22.
//

#ifndef EX16_58_VEC_H
#define EX16_58_VEC_H


#include <memory>
#include <string>
#include <utility>

template <typename T>
class Vec {
public:
  Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

  Vec(const Vec&);
  Vec& operator=(const Vec&);
  Vec(Vec&&) noexcept;
  Vec& operator=(Vec&&) noexcept;
  ~Vec();

  T& operator[](size_t n) { return elements[n]; }
  const T& operator[](size_t n) const { return elements[n]; }

  void push_back(const T&);
  template<class... Args> void emplace_back(Args&&...);

  [[nodiscard]] size_t size() const { return first_free - elements; }
  [[nodiscard]] size_t capacity() const { return cap - elements; }
  [[nodiscard]] T* begin() const { return elements; }
  [[nodiscard]] T* end() const { return first_free; }

  void reserve(size_t);
  void resize(size_t);
  void resize(size_t, const T&);

private:
  static std::allocator<T> alloc;

  void chk_n_alloc() { if (size() == capacity()) reallocate(); }
  static std::pair<T*, T*> alloc_n_copy(const T*, const T*);
  void alloc_n_move(size_t);
  void free();
  void reallocate();

  T *elements;
  T *first_free;
  T *cap;
};

// Remember to define the static member
template <typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

template<typename T>
void Vec<T>::free() {
  if (elements) {
    for (auto p = first_free; p != elements; )
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

template<typename T>
void Vec<T>::reallocate() {
  auto new_cap = size() ? 2 * size() : 1;
  alloc_n_move(new_cap);
}

template<typename T>
void Vec<T>::alloc_n_move(size_t new_cap) {
  auto new_data = alloc.allocate(new_cap);
  auto dest = new_data;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = new_data;
  first_free = dest;
  cap = elements + new_cap;
}

template<typename T>
Vec<T>::Vec(const Vec &v) {
  auto new_data = alloc_n_copy(v.begin(), v.end());
  elements = new_data.first;
  first_free = cap = new_data.second;
}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

template<typename T>
Vec<T>::Vec(Vec &&v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap) {
  v.elements = v.first_free = v.cap = nullptr;
}

template<typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

template<typename T>
Vec<T>::~Vec() {
  free();
}

template<typename T>
void Vec<T>::push_back(const T &data) {
  chk_n_alloc();
  alloc.construct(first_free++, data);
}

template<typename T>
void Vec<T>::reserve(size_t new_cap) {
  if (new_cap <= capacity())
    return;
  alloc_n_move(new_cap);
}

template<typename T>
void Vec<T>::resize(size_t new_size) {
  resize(new_size, T());
}

template<typename T>
void Vec<T>::resize(size_t new_size, const T &data) {
  if (new_size > size()) {
    if (new_size > capacity())
      reserve(2 * new_size);
    for (size_t i = size(); i != new_size; ++i)
      alloc.construct(first_free++, data);
  } else if (new_size < size()) {
    while (first_free != elements + new_size)
      alloc.destroy(--first_free);
  }
}

template<typename T>
template<class... Args>
inline void Vec<T>::emplace_back(Args&&... args) {
  chk_n_alloc();
  alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (auto iter_lhs = lhs.begin(), iter_rhs = rhs.begin();
       iter_lhs != lhs.end() && iter_rhs != rhs.end();
       ++iter_lhs, ++iter_rhs)
    if (*iter_lhs != *iter_rhs)
      return false;
  return true;
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs == rhs);
}


#endif //EX16_58_VEC_H
