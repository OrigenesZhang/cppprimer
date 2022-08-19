#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

auto get_first_expensive(const std::vector<Sales_data> &vec, double price) -> decltype(vec.begin()) {
  auto f = std::mem_fn(&Sales_data::avg_price);
  return std::find_if(vec.begin(), vec.end(), [&](const Sales_data &s) { return price < f(s); });
}

int main() {
  std::vector<Sales_data> vec{
    Sales_data("book1", 3, 1.5),
    Sales_data("book2", 7, 7.2),
    Sales_data("book3", 1, 7.5)
  };
  auto it = get_first_expensive(vec, 7);
  std::cout << *it << std::endl;
}
