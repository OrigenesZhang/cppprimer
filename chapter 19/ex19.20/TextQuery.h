//
// Created by Bin Zhang on 21/8/22.
//

#ifndef EX19_20_TEXTQUERY_H
#define EX19_20_TEXTQUERY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class TextQuery {
public:
  class QueryResult;
  using line_no = std::vector<std::string>::size_type;
  explicit TextQuery(std::ifstream&);
  [[nodiscard]] QueryResult query(const std::string&) const;

private:
  std::shared_ptr<std::vector<std::string>> input_file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> matches;
};

class TextQuery::QueryResult {
  friend std::ostream &print(std::ostream&, const QueryResult&);

public:
  QueryResult(
      std::string s,
      std::shared_ptr<std::set<line_no>> lines,
      std::shared_ptr<std::vector<std::string>> input
  ) : word(std::move(s)), line_nos(std::move(lines)), input_file(std::move(input)) {}

private:
  std::string word;
  std::shared_ptr<std::set<line_no>> line_nos;
  std::shared_ptr<std::vector<std::string>> input_file;
};

std::ostream& print(std::ostream&, const TextQuery::QueryResult&);


#endif //EX19_20_TEXTQUERY_H
