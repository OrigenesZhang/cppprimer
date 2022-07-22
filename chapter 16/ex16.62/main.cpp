#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

int main() {
  std::unordered_set<Sales_data> set;
  Sales_data sd("Book 1", 10, 2.99);
  set.emplace(sd);
  set.emplace("Book 2", 5, 1.78);
  for (const auto &item : set)
    std::cout << "The hash code of " << item.isbn() << " is "
    << std::hex << std::hash<Sales_data>()(item) << std::endl;
}
