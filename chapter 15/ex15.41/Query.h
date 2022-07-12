//
// Created by Bin Zhang on 12/7/22.
//

#ifndef EX15_41_QUERY_H
#define EX15_41_QUERY_H


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
  Query(const Query &rhs): q(rhs.q), use(rhs.use) { ++*use; }
  Query &operator=(const Query&);
  ~Query() noexcept;
  [[nodiscard]] QueryResult eval(const TextQuery& t) const { return q->eval(t); }
  [[nodiscard]] std::string rep() const { return q->rep(); }
private:
  Query(Query_base *query): q(query), use(new size_t(1)) {}
  Query_base *q;
  size_t *use;
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
  explicit NotQuery(const Query& q): query(q) {}
  [[nodiscard]] std::string rep() const override { return "~(" + query.rep() + ")"; }
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
  Query query;
};

inline Query operator~(const Query &operand) {
  return new NotQuery(operand);
}

class BinaryQuery: public Query_base {
protected:
  BinaryQuery(const Query& l, const Query& r, std::string s): lhs(l), rhs(r), opSym(std::move(s)) {}
  [[nodiscard]] std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
  Query lhs, rhs;
  std::string opSym;
};

class AndQuery: public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query& l, const Query& r): BinaryQuery(l, r, "&") {}
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
  return new AndQuery(lhs, rhs);
}

class OrQuery: public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query& l, const Query& r): BinaryQuery(l, r, "|") {}
  [[nodiscard]] QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
  return new OrQuery(lhs, rhs);
}

inline Query::Query(const std::string &s) : q(new WordQuery(s)), use(new size_t(1)) {}


#endif //EX15_41_QUERY_H
