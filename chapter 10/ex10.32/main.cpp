#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include "../../include/Sales_item.h"

int main() {
  std::istream_iterator<Sales_item> is(std::cin), eof;
  std::vector<Sales_item> vec(is, eof);
  std::sort(vec.begin(), vec.end(), compareIsbn);
  for (auto beg_iter = vec.cbegin(), end_iter = beg_iter; beg_iter != vec.cend(); beg_iter = end_iter) {
    end_iter = std::find_if_not(beg_iter, vec.cend(), [beg_iter](const Sales_item &s) {
      return beg_iter->isbn() == s.isbn();
    });
    std::cout << std::accumulate(beg_iter, end_iter, Sales_item(beg_iter->isbn())) << std::endl;
  }
}
