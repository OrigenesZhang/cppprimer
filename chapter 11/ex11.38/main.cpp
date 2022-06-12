#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::string;
using std::ifstream;
using std::unordered_map;

unordered_map<string, string> build_map(ifstream &ifs) {
  unordered_map<string, string> trans_map;
  string from, to;
  while (ifs >> from && getline(ifs, to))
    if (to.size() > 1)
      trans_map[from] = to.substr(1);
  return trans_map;
}

const string &transform(const string &from, const unordered_map<string, string> &trans_map) {
  auto iter = trans_map.find(from);
  if (iter == trans_map.end())
    return from;
  return iter->second;
}

void word_transform(ifstream &ifs_map, ifstream &ifs_content) {
  auto trans_map = build_map(ifs_map);
  string line;
  while (getline(ifs_content, line)) {
    std::istringstream iss(line);
    string word;
    bool is_first = true;
    while (iss >> word) {
      if (!is_first) std::cout << ' ';
      std::cout << transform(word, trans_map);
      is_first = false;
    }
    std::cout << std::endl;
  }
}

int main() {
  ifstream ifs_map("transform.in"), ifs_content("content.in");
  if (ifs_map && ifs_content)
    word_transform(ifs_map, ifs_content);
  else
    std::cerr << "Cannot find the documents" << std::endl;
}
