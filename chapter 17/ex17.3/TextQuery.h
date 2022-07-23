//
// Created by Bin Zhang on 23/7/22.
//

#ifndef EX17_3_TEXTQUERY_H
#define EX17_3_TEXTQUERY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  using result_tuple =
      std::tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>>;
  explicit TextQuery(std::ifstream&);
  [[nodiscard]] result_tuple query(const std::string&) const;
private:
  std::shared_ptr<std::vector<std::string>> input_file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> matches;
};

std::ostream& print(std::ostream&, const TextQuery::result_tuple&);


#endif //EX17_3_TEXTQUERY_H
