//
// Created by Bin Zhang on 25/6/22.
//

#ifndef EX13_40_STRVEC_H
#define EX13_40_STRVEC_H


#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec&);
  StrVec(std::initializer_list<std::string>);
  StrVec &operator=(const StrVec&);
  ~StrVec();
  void push_back(const std::string&);
  [[nodiscard]] size_t size() const { return first_free - elements; }
  [[nodiscard]] size_t capacity() const { return cap - elements; }
  [[nodiscard]] std::string *begin() const { return elements; }
  [[nodiscard]] std::string *end() const { return first_free; }
  void reserve(size_t);
  void resize(size_t);
  void resize(size_t, const std::string&);
private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() { if (size() == capacity()) reallocate(); }
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
  void alloc_n_move(size_t);
  void free();
  void reallocate();
  void range_initialize(const std::string *, const std::string *);
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};


#endif //EX13_40_STRVEC_H
