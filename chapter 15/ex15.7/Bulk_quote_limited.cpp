//
// Created by Bin Zhang on 5/7/22.
//

#include "Bulk_quote_limited.h"

double Bulk_quote_limited::net_price(size_t n) const {
  if (n > max_qty)
    return max_qty * price * (1 - discount) + (n - max_qty) * price;
  else
    return n * price * (1 - discount);
}
