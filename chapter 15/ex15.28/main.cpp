#include <iostream>
#include <vector>
#include "../ex15.15/Quote.h"
#include "../ex15.15/Bulk_quote.h"

int main() {
  std::vector<Quote> vec;
  for (size_t i = 0; i < 10; ++i)
    vec.push_back(Bulk_quote("bq", 10.5, 5, 0.3));
  double total = 0;
  for (const auto &q : vec)
    total += q.net_price(10);
  std::cout << total << std::endl;
}
