#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

void add_family(map<string, vector<string>> &families, const string &family) {
  if (families.find(family) == families.end())
    families[family] = {};
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child) {
  if (families.find(family) != families.end())
    families[family].push_back(child);
}

int main() {
  map<string, vector<string>> families;
  add_family(families, "f1");
  add_family(families, "f2");
  add_family(families, "f1");
  add_child(families, "f1", "c1");
  add_child(families, "f2", "c2");
  add_child(families, "f1", "c3");
  add_child(families, "f3", "c4");
  for (const auto &[k, vec] : families) {
    std::cout << "Family " << k << " has child(ren): ";
    for (const auto &v : vec)
      std::cout << v << " ";
    std::cout << std::endl;
  }
}
