#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>

using std::vector;
using std::string;
using std::ifstream;
using std::map;

map<string, vector<string>> build_map(ifstream &ifs) {
  map<string, vector<string>> trans_map;
  string from, to;
  while (ifs >> from && getline(ifs, to))
    if (to.size() > 1)
      trans_map[from].push_back(to.substr(1));
  return trans_map;
}

const string &transform(const string &from, const map<string, vector<string>> &trans_map) {
  auto iter = trans_map.find(from);
  if (iter == trans_map.end())
    return from;
  static std::default_random_engine e(time(nullptr));
  std::uniform_int_distribution<size_t> u(0, iter->second.size() - 1);
  return iter->second[u(e)];
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
