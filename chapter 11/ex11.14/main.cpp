#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::string;
using std::vector;

void add_family(map<string, vector<std::pair<string, string>>> &families, const string &family) {
  if (families.find(family) == families.end())
    families[family] = {};
}

void add_child(map<string, vector<std::pair<string, string>>> &families,
               const string &family, const string &child, const string &birthday) {
  if (families.find(family) != families.end())
    families[family].emplace_back(child, birthday);
}

int main() {
  map<string, vector<std::pair<string, string>>> families;
  add_family(families, "f1");
  add_family(families, "f2");
  add_family(families, "f1");
  add_child(families, "f1", "c1", "03072002");
  add_child(families, "f2", "c2", "15032002");
  add_child(families, "f1", "c3", "15032002");
  add_child(families, "f3", "c4", "17032002");
  for (const auto &[k, vec] : families) {
    std::cout << "Family " << k << " has child(ren):" << std::endl;
    for (const auto &v : vec)
      std::cout << "Name: " << v.first << ", Birthday: " << v.second << std::endl;
    std::cout << std::endl;
  }
}
