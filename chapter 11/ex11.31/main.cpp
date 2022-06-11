#include <iostream>
#include <string>
#include <map>

using std::string;

int main() {
  std::multimap<string, string> authors{
    {"a", "v1"},
    {"b", "v2"},
    {"a", "v2"},
    {"b", "v3"},
    {"c", "v1"}
  };
  string author = "a", work = "v1";
  auto [beg, end] = authors.equal_range(author);
  for (auto iter = beg; iter != end; ++iter)
    if (iter->second == work) {
      authors.erase(iter);
      break;
    }
  for (const auto &[k, v] : authors)
    std::cout << k << ' ' << v << std::endl;
}