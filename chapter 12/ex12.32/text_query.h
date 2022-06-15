//
// Created by Bin Zhang on 16/6/22.
//

#ifndef EX12_32_TEXT_QUERY_H
#define EX12_32_TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include "../ex12.22/str_blob.h"

class QueryResult;

class TextQuery {
public:
  explicit TextQuery(std::ifstream&);
  [[nodiscard]] QueryResult query(const std::string&) const;
private:
  StrBlob file;
  std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> matches;
};

class QueryResult {
public:
  friend std::ostream& print(std::ostream&, const QueryResult&);
  QueryResult(
      std::string s,
      std::shared_ptr<std::set<StrBlob::size_type>> lines,
      StrBlob input
  ) : word(std::move(s)), line_nos(std::move(lines)), file(std::move(input)) {}
private:
  std::string word;
  std::shared_ptr<std::set<StrBlob::size_type>> line_nos;
  StrBlob file;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif //EX12_32_TEXT_QUERY_H
