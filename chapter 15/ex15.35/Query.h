//
// Created by Bin Zhang on 12/7/22.
//

#ifndef EX15_35_QUERY_H
#define EX15_35_QUERY_H


#include <string>
#include <memory>
#include <utility>
#include "TextQuery.h"
#include "Query_base.h"

class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
public:
  Query(const std::string&);
  [[nodiscard]] QueryResult eval(const TextQuery& t) const { return q->eval(t); }
  [[nodiscard]] std::string rep() const { return q->rep(); }
private:
  explicit Query(std::shared_ptr<Query_base> query): q(std::move(query)) {}
  std::shared_ptr<Query_base> q;
};


#endif //EX15_35_QUERY_H
