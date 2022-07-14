//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_24_BLOB_H
#define EX16_24_BLOB_H


#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>


template <typename T>
class Blob {
public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  Blob() = default;
  Blob(std::initializer_list<T>);
  template<typename It> Blob(It, It);

  size_type size() const { return data->size(); }
  [[nodiscard]] bool empty() const { return data->empty(); }

  void push_back(const T& t) { data->push_back(t); }
  void push_back(T&& t) { data->push_back(std::move(t)); }
  void pop_back();

  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  T& operator[](size_type);
  const T& operator[](size_type) const;

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type, const std::string&) const;
};

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}

template<typename T>
void Blob<T>::check(Blob::size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

template<typename T>
T &Blob<T>::front() {
  check(0, "front on empty Blob");
  return data->front();
}

template<typename T>
const T &Blob<T>::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

template<typename T>
T &Blob<T>::back() {
  check(0, "back on empty Blob");
  return data->back();
}

template<typename T>
const T &Blob<T>::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

template<typename T>
T &Blob<T>::operator[](Blob::size_type i) {
  check(i, "subscript out of range");
  return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[](Blob::size_type i) const {
  check(i, "subscript out of range");
  return (*data)[i];
}

template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>>(b, e)) {}


#endif //EX16_24_BLOB_H
