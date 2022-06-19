//
// Created by Bin Zhang on 19/6/22.
//

#ifndef EX13_26_STRBLOB_H
#define EX13_26_STRBLOB_H


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

  StrBlob(const StrBlob& sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}

  StrBlob& operator=(const StrBlob&);

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


#endif //EX13_26_STRBLOB_H
