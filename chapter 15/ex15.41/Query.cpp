//
// Created by Bin Zhang on 12/7/22.
//

#include "Query.h"
#include <algorithm>

Query &Query::operator=(const Query &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
    delete q;
    delete use;
  }
  q = rhs.q;
  use = rhs.use;
  return *this;
}

Query::~Query() noexcept {
  if (--*use == 0) {
    delete q;
    delete use;
  }
}

QueryResult OrQuery::eval(const TextQuery &text) const {
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return {rep(), ret_lines, left.get_file()};
}

QueryResult AndQuery::eval(const TextQuery &text) const {
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                        std::inserter(*ret_lines, ret_lines->begin()));
  return {rep(), ret_lines, left.get_file()};
}

QueryResult NotQuery::eval(const TextQuery &text) const {
  auto result = query.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  for (size_t n = 0; n != sz; ++n) {
    if (beg == end || *beg != n)
      ret_lines->insert(n);
    else if (beg != end)
      ++beg;
  }
  return {rep(), ret_lines, result.get_file()};
}
