//
// Created by Bin Zhang on 23/7/22.
//

#include "TextQuery.h"
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

TextQuery::result_tuple TextQuery::query(const std::string &q) const {
  static std::shared_ptr<std::set<line_no>> empty_result(new std::set<line_no>);
  auto result_iter = matches.find(q);
  if (result_iter == matches.end())
    return {q, empty_result, input_file};
  return {q, result_iter->second, input_file};
}

std::ostream& print(std::ostream &os, const TextQuery::result_tuple &qr) {
  auto &[word, line_nos, input_file] = qr;
  os << word << " occurs " << line_nos->size() << (line_nos->size() > 1 ? " times" : " time") << std::endl;
  for (auto id : *line_nos)
    os << "\t(line " << id << ") " << (*input_file)[id] << std::endl;
  return os;
}
