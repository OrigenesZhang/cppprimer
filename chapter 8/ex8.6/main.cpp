#include <iostream>
#include <fstream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

int main(int argc, char **argv) {
    Sales_data total;
    double price;
    std::fstream in(argv[1]);
    if (in >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (in >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << std::endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}