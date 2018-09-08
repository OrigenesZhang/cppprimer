#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    std::string isbn() const {
        return bookNo;
    }

    Sales_data& combine(const Sales_data&);

    double avg_prive() const;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_prive() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

int main() {
    Sales_data total;
    double price;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                std::cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}