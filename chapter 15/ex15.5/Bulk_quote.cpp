//
// Created by Bin Zhang on 5/7/22.
//

#include "Bulk_quote.h"

double Bulk_quote::net_price(size_t n) const {
  if (n >= min_qty)
    return n * (1 - discount) * price;
  else
    return Quote::net_price(n);
}
