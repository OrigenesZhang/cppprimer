#include <iostream>

std::istream &func(std::istream &is) {
    auto old_state = is.rdstate();
    std::string s;
    while (is >> s) std::cout << s << ' ';
    std::cout << std::endl;
    is.clear();
    is.setstate(old_state);
    return is;
}

int main() {
    func(std::cin);
    return 0;
}