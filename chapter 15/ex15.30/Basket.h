//
// Created by Bin Zhang on 11/7/22.
//

#ifndef EX15_30_BASKET_H
#define EX15_30_BASKET_H

#include <iostream>
#include <memory>
#include <set>
#include "Quote.h"

class Basket {
public:
  void add_item(const Quote&);
  void add_item(Quote&&);
  double total_receipt(std::ostream&) const;
private:
  static bool compare(const std::shared_ptr<Quote>&, const std::shared_ptr<Quote>&);
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};


#endif //EX15_30_BASKET_H
