#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include "../ex17.4/Sales_data.h"

using matches = std::pair<
    std::vector<Sales_data>::size_type,
    std::pair<std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator>
>;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book) {
  std::vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it) {
    auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second)
      ret.emplace_back(it - files.cbegin(), std::make_pair(found.first, found.second));
  }
  return ret;
}

void reportResults(std::istream &is, std::ostream &os, const std::vector<std::vector<Sales_data>> &files) {
  std::string s;
  while (is >> s) {
    auto trans = findBook(files, s);
    if (trans.empty()) {
      std::cout << s << " not found in any stores" << std::endl;
      continue;
    }
    for (const auto &store : trans)
      os << "store " << store.first << " sales: "
         << std::accumulate(store.second.first, store.second.second, Sales_data(s))
         << std::endl;
  }
}

int main() {
  std::vector<std::vector<Sales_data>> files = {
      {Sales_data("Book1", 5, 7.9), Sales_data("Book2", 3, 7.2), Sales_data("Book2", 6, 2.1)},
      {Sales_data("Book0", 10, 15.5), Sales_data("Book1", 1, 1.0), Sales_data("Book1", 2, 15.4)}
  };
  reportResults(std::cin, std::cout, files);
}
