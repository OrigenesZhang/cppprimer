//
// Created by Bin Zhang on 29/6/22.
//

#ifndef EX14_18_STRBLOB_H
#define EX14_18_STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
  friend bool operator==(const StrBlob&, const StrBlob&);
  friend bool operator!=(const StrBlob&, const StrBlob&);
  friend bool operator<(const StrBlob&, const StrBlob&);
  friend bool operator>(const StrBlob&, const StrBlob&);
  friend bool operator<=(const StrBlob&, const StrBlob&);
  friend bool operator>=(const StrBlob&, const StrBlob&);
public:
  typedef std::vector<std::string>::size_type size_type;
  friend class StrBlobPtr;
  StrBlobPtr begin();
  StrBlobPtr end();
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

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  [[nodiscard]] std::string &deref() const;
  StrBlobPtr &incr();
private:
  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);


#endif //EX14_18_STRBLOB_H
