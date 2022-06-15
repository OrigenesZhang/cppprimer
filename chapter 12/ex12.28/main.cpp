#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

using LineNo = std::vector<std::string>::size_type;

void read_file(
    std::ifstream &ifs, std::vector<std::string> &lines, std::map<std::string, std::set<LineNo>> &matches) {
  LineNo tot{0};
  for (std::string line; getline(ifs, line); ++tot) {
    lines.push_back(line);
    std::istringstream iss(line);
    for (std::string word; iss >> word; ) {
      auto end_iter = std::remove_if(word.begin(), word.end(), ispunct);
      word.erase(end_iter, word.end());
      if (matches.find(word) == matches.end())
        matches[word] = std::set<LineNo>();
      matches[word].insert(tot);
    }
  }
}

void runQueries(std::ifstream &infile) {
  std::vector<std::string> lines;
  std::map<std::string, std::set<LineNo>> matches;
  read_file(infile, lines, matches);
  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    auto result_iter = matches.find(s);
    auto print = [&](std::ostream &os) -> std::ostream& {
      auto get_size = [&]() -> LineNo {
        if (result_iter == matches.end())
          return 0;
        return result_iter->second.size();
      };
      os << s << " occurs " << get_size() << (get_size() > 1 ? " times" : " time") << std::endl;
      if (get_size() != 0) {
        for (auto id : result_iter->second)
          os << "\t(line " << id << ") " << lines[id] << std::endl;
      }
      return os;
    };
    print(std::cout) << std::endl;
  }
}

int main() {
  std::ifstream ifs("../../ex12.27/input.in");
  runQueries(ifs);
}
