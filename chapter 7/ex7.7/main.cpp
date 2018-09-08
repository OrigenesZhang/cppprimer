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

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret = lhs;
    ret.combine(rhs);
    return ret;
}

std::istream& read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_prive();
    return os;
}

int main() {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(std::cout, total);
                std::cout << '\n';
                total = trans;
            }
        }
        print(std::cout, total);
        std::cout << '\n';
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}