//
// Created by Bin Zhang on 12/7/22.
//

#ifndef EX15_42_QUERY_BASE_H
#define EX15_42_QUERY_BASE_H


#include <string>
#include "TextQuery.h"

class Query_base {
  friend class Query;
protected:
  using line_no = TextQuery::line_no;
  virtual ~Query_base() = default;
private:
  [[nodiscard]] virtual QueryResult eval(const TextQuery&) const = 0;
  [[nodiscard]] virtual std::string rep() const = 0;
};


#endif //EX15_42_QUERY_BASE_H
