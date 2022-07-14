//
// Created by Bin Zhang on 14/7/22.
//

#include "TextQuery.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs) : input_file(new std::vector<std::string>, DebugDelete()) {
  line_no tot{0};
  for (std::string line; getline(ifs, line); ++tot) {
    input_file->push_back(line);
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto end_iter = std::remove_if(word.begin(), word.end(), ispunct);
      word.erase(end_iter, word.end());
      auto &set = matches[word];
      if (set == nullptr)
        set.reset(new std::set<line_no>, DebugDelete());
      set->insert(tot);
    }
  }
}

QueryResult TextQuery::query(const std::string &q) const {
  static std::shared_ptr<std::set<line_no>> empty_result(new std::set<line_no>, DebugDelete());
  auto result_iter = matches.find(q);
  if (result_iter == matches.end())
    return {q, empty_result, input_file};
  return {q, result_iter->second, input_file};
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
  os << qr.word << " occurs " << qr.line_nos->size() << (qr.line_nos->size() > 1 ? " times" : " time") << std::endl;
  for (auto id : *qr.line_nos)
    os << "\t(line " << id << ") " << (*qr.input_file)[id] << std::endl;
  return os;
}
