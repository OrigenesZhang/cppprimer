//
// Created by Bin Zhang on 16/6/22.
//

#include "text_query.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs) {
  StrBlob::size_type tot{0};
  for (std::string line; getline(ifs, line); ++tot) {
    file.push_back(line);
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto end_iter = std::remove_if(word.begin(), word.end(), ispunct);
      word.erase(end_iter, word.end());
      auto &set = matches[word];
      if (set == nullptr)
        set.reset(new std::set<StrBlob::size_type>);
      set->insert(tot);
    }
  }
}

QueryResult TextQuery::query(const std::string &q) const {
  static std::shared_ptr<std::set<StrBlob::size_type>> empty_result(new std::set<StrBlob::size_type>);
  auto result_iter = matches.find(q);
  if (result_iter == matches.end())
    return {q, empty_result, file};
  return {q, result_iter->second, file};
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.word << " occurs " << qr.line_nos->size() << (qr.line_nos->size() > 1 ? " times" : " time") << std::endl;
  for (auto id : *qr.line_nos) {
    ConstStrBlobPtr ptr(qr.file, id);
    os << "\t(line " << id + 1 << ") " << ptr.deref() << std::endl;
  }
  return os;
}
