#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    Sales_data() : bookNo(""), units_sold(0), revenue(0) {}
};

int main() {
    return 0;
}