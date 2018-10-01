#include <iostream>

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {
        std::cout << 3 << std::endl;
    }

    Sales_data() : Sales_data("", 0, 0) {
        std::cout << 0 << std::endl;
    }

    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
        std::cout << 1 << std::endl;
    }

    Sales_data(std::istream &is) : Sales_data() {
        read(is, *this);
        std::cout << "r" << std::endl;
    }

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

inline double Sales_data::avg_prive() const {
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
    Sales_data s1("this", 1, 2.5);
    std::cout << "!\n";
    Sales_data s2(std::cin);
    std::cout << "!\n";
    Sales_data s3;
    std::cout << "!\n";
    Sales_data s4("that");
    std::cout << "!\n";
    return 0;
}