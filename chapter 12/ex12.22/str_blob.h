//
// Created by Bin Zhang on 13/6/22.
//

#ifndef EX12_22_STR_BLOB_H
#define EX12_22_STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class ConstStrBlobPtr;

class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;

  friend class ConstStrBlobPtr;

  [[nodiscard]] ConstStrBlobPtr begin() const;

  [[nodiscard]] ConstStrBlobPtr end() const;

  StrBlob();

  StrBlob(std::initializer_list<std::string> il);

  [[nodiscard]] size_type size() const { return data->size(); };

  [[nodiscard]] bool empty() const { return data->empty(); };

  void push_back(const std::string &t) { data->push_back(t); };

  void pop_back();

  std::string &front();

  [[nodiscard]] const std::string &front() const;

  std::string &back();

  [[nodiscard]] const std::string &back() const;

private:
  std::shared_ptr<std::vector<std::string>> data;

  void check(size_type i, const std::string &msg) const;
};

class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr(0) {}

  explicit ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  [[nodiscard]] const std::string &deref() const;

  ConstStrBlobPtr &incr();

  bool operator!=(const ConstStrBlobPtr &rhs) const { curr != rhs.curr; }

private:
  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;

  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

const std::string &ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
  check(curr, "increment past end of ConstStrBlobPtr");
  ++curr;
  return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound ConstStrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
  check(0, "front on empty str_blob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty str_blob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty str_blob");
  return data->pop_back();
}

const std::string &StrBlob::front() const {
  check(0, "front on empty str_blob");
  return data->front();
}

const std::string &StrBlob::back() const {
  check(0, "back on empty str_blob");
  return data->back();
}

#endif //EX12_22_STR_BLOB_H
