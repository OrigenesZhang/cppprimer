//
// Created by Bin Zhang on 29/6/22.
//

#include "StrBlob.h"
#include <algorithm>

std::string &StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs > rhs);;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs < rhs);
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

StrBlobPtr StrBlob::begin() {
  return {*this};
}

StrBlobPtr StrBlob::end() {
  return {*this, data->size()};
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs < rhs);
}
