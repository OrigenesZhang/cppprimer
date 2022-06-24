//
// Created by Bin Zhang on 25/6/22.
//

#ifndef EX13_42_TEXTQUERY_H
#define EX13_42_TEXTQUERY_H


#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include "../ex13.40/StrVec.h"

class QueryResult;

class TextQuery {
public:
  explicit TextQuery(std::ifstream&);
  [[nodiscard]] QueryResult query(const std::string&) const;
private:
  std::shared_ptr<StrVec> input_file;
  std::map<std::string, std::shared_ptr<std::set<size_t>>> matches;
};

class QueryResult {
public:
  friend std::ostream& print(std::ostream&, const QueryResult&);
  QueryResult(
      std::string s,
      std::shared_ptr<std::set<size_t>> lines,
      std::shared_ptr<StrVec> input
  ) : word(std::move(s)), line_nos(std::move(lines)), input_file(std::move(input)) {}
private:
  std::string word;
  std::shared_ptr<std::set<size_t>> line_nos;
  std::shared_ptr<StrVec> input_file;
};

std::ostream& print(std::ostream&, const QueryResult&);


#endif //EX13_42_TEXTQUERY_H
