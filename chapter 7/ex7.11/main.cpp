#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    Sales_data() = default;

    Sales_data(const std::string &s) : bookNo(s) {}

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}

    Sales_data(std::istream &is);

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

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

std::ostream& print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_prive();
    return os;
}

int main() {
    Sales_data s1;
    Sales_data s2("this is s2");
    Sales_data s3("this is s3", 15, 0.2);
    Sales_data s4(std::cin);
    print(std::cout, s1);
    std::cout << '\n';
    print(std::cout, s2);
    std::cout << '\n';
    print(std::cout, s3);
    std::cout << '\n';
    print(std::cout, s4);
    std::cout << '\n';
    return 0;
}