//
// Created by Bin Zhang on 12/7/22.
//

#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs) : input_file(new std::vector<std::string>) {
  line_no tot{0};
  for (std::string line; getline(ifs, line); ++tot) {
    input_file->push_back(line);
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto end_iter = std::remove_if(word.begin(), word.end(), ispunct);
      word.erase(end_iter, word.end());
      auto &set = matches[word];
      if (set == nullptr)
        set.reset(new std::set<line_no>);
      set->insert(tot);
    }
  }
}

QueryResult TextQuery::query(const std::string &q) const {
  static std::shared_ptr<std::set<line_no>> empty_result(new std::set<line_no>);
  auto result_iter = matches.find(q);
  if (result_iter == matches.end())
    return {q, empty_result, input_file};
  return {q, result_iter->second, input_file};
}

std::ostream& print(std::ostream &os, const QueryResult &qr, size_t head, size_t tail) {
  std::vector<TextQuery::line_no> results;
  for (auto id : *qr.line_nos)
    if (head <= id && id <= tail)
      results.push_back(id);
  os << qr.word << " occurs " << results.size() << (results.size() > 1 ? " times" : " time") << std::endl;
  for (auto id : results)
    os << "\t(line " << id << ") " << (*qr.input_file)[id] << std::endl;
  return os;
}
