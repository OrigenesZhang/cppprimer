//
// Created by Bin Zhang on 19/6/22.
//

#include "StrBlob.h"

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

ConstStrBlobPtr StrBlob::begin() const {
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr(*this, data->size());
}

StrBlob &StrBlob::operator=(const StrBlob &rhs) {
  if (this !=&rhs)
    data = std::make_shared<std::vector<std::string>>(*rhs.data);
  return *this;
}
