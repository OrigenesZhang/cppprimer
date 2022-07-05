#include <iostream>
#include "Quote.h"

double price_total(std::ostream &os, const Quote& item, size_t n) {
  double total_price = item.net_price(n);
  os << "ISBN: " << item.isbn() << "# sold: " << n << " total price: " << total_price << std::endl;
  return total_price;
}

int main() {}
