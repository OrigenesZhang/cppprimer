//
// Created by Bin Zhang on 12/7/22.
//

#ifndef EX15_42_QUERY_H
#define EX15_42_QUERY_H


#include <string>
#include <memory>
#include <utility>
#include <iostream>
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
  Query(std::shared_ptr<Query_base> query): q(std::move(query)) {}
  std::shared_ptr<Query_base> q;
};

class WordQuery: public Query_base {
  friend class Query;
  explicit WordQuery(std::string s): query_word(std::move(s)) {}
  [[nodiscard]] QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
  [[nodiscard]] std::string rep() const override { return query_word; }
  std::string query_word;
};

class NotQuery: public Query_base {
  friend Query operator~(const Query&);
  explicit NotQuery(Query q): query(std::move(q)) {}
  [[nodiscard]] std::string rep() const override { return "~(" + query.rep() + ")"; }
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
  Query query;
};

inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
protected:
  BinaryQuery(Query l, Query r, std::string s): lhs(std::move(l)), rhs(std::move(r)), opSym(std::move(s)) {}
  [[nodiscard]] std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
  Query lhs, rhs;
  std::string opSym;
};

class AndQuery: public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(Query l, Query r): BinaryQuery(std::move(l), std::move(r), "&") {}
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery: public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(Query l, Query r): BinaryQuery(std::move(l), std::move(r), "|") {}
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}


#endif //EX15_42_QUERY_H
