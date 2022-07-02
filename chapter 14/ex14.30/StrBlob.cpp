//
// Created by Bin Zhang on 2/7/22.
//

#include "StrBlob.h"

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

inline std::string &StrBlobPtr::operator[](size_t n) {
  auto p = check(curr, "dereference out of range");
  return (*p)[n];
}

inline const std::string &StrBlobPtr::operator[](size_t n) const {
  auto p = check(curr, "dereference out of range");
  return (*p)[n];
}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  StrBlobPtr ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  StrBlobPtr ret = *this;
  --*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
  curr += n;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
  curr += n;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const {
  StrBlobPtr ret = *this;
  ret += n;
  return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const {
  StrBlobPtr ret = *this;
  ret -= n;
  return ret;
}

std::string &StrBlobPtr::operator*() const {
  auto p = check(curr, "deference past end");
  return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const {
  return & this->operator*();
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

inline std::string &StrBlob::operator[](size_t n) {
  check(n, "out of range");
  return data->at(n);
}

inline const std::string &StrBlob::operator[](size_t n) const {
  check(n, "out of range");
  return data->at(n);
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

const std::string &ConstStrBlobPtr::operator*() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

const std::string *ConstStrBlobPtr::operator->() const {
  return & this->operator*();
}
