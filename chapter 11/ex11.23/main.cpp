#include <iostream>
#include <map>
#include <string>

using std::multimap;
using std::string;

void add_child(multimap<string, string> &families, const string &family, const string &child) {
  families.insert({family, child});
}

int main() {
  multimap<string, string> families;
  add_child(families, "f1", "c1");
  add_child(families, "f2", "c2");
  add_child(families, "f1", "c3");
  add_child(families, "f3", "c4");
  for (const auto &[k, v] : families)
    std::cout << "Child " << v << " belongs to family " << k << std::endl;
}
