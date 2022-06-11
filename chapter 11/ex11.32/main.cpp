#include <iostream>
#include <string>
#include <map>
#include <set>

using std::string;

int main() {
  std::multimap<string, string> authors{
      {"a", "v1"},
      {"b", "v2"},
      {"a", "v2"},
      {"b", "v3"},
      {"c", "v1"}
  };
  // Why do we need this extra step?
  // The order of the key-value pairs whose keys compare equivalent
  // is the order of insertion and does not change. (since C++11)
  // ref: https://en.cppreference.com/w/cpp/container/multimap
  std::map<string, std::multiset<string>> ordered_authors;
  for (const auto &[k, v] : authors)
    ordered_authors[k].insert(v);
  for (const auto &[k, s] : ordered_authors)
    for (const auto &v : s)
      std::cout << k << ' ' << v << std::endl;
}