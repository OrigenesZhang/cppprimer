#include <iostream>
#include <set>
#include "../../include/Sales_item.h"

bool compare(const Sales_item &b1, const Sales_item &b2) {
  return b1.isbn() < b2.isbn();
}

int main() {
  std::multiset<Sales_item, bool (*) (const Sales_item&, const Sales_item &)> bookstore(compare);
}
