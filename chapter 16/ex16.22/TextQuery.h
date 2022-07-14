//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_22_TEXTQUERY_H
#define EX16_22_TEXTQUERY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "DebugDelete.h"

class QueryResult;

class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  explicit TextQuery(std::ifstream&);
  [[nodiscard]] QueryResult query(const std::string&) const;
private:
  std::shared_ptr<std::vector<std::string>> input_file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> matches;
};

class QueryResult {
public:
  friend std::ostream& print(std::ostream&, const QueryResult&);
  QueryResult(
      std::string s,
      std::shared_ptr<std::set<TextQuery::line_no>> lines,
      std::shared_ptr<std::vector<std::string>> input
  ) : word(std::move(s)), line_nos(std::move(lines)), input_file(std::move(input)) {}
private:
  std::string word;
  std::shared_ptr<std::set<TextQuery::line_no>> line_nos;
  std::shared_ptr<std::vector<std::string>> input_file;
};

std::ostream& print(std::ostream&, const QueryResult&);


#endif //EX16_22_TEXTQUERY_H
