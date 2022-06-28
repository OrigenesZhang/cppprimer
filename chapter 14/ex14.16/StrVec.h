//
// Created by Bin Zhang on 29/6/22.
//

#ifndef EX14_16_STRVEC_H
#define EX14_16_STRVEC_H

#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec&);
  StrVec &operator=(const StrVec&);
  StrVec(StrVec&&) noexcept;
  StrVec &operator=(StrVec&&) noexcept;
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
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

#endif //EX14_16_STRVEC_H
