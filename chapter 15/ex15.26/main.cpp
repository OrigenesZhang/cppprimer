#include <iostream>
#include "Bulk_quote.h"

int main() {
  Bulk_quote bq1;
  Bulk_quote bq2("bq2", 10.5, 5, 0.3);
  bq2 = std::move(bq1);
  std::cout << "-------------------------------------" << std::endl;
  bq1 = bq2;
  std::cout << "-------------------------------------" << std::endl;
}
