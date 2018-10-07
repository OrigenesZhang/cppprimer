#include <iostream>
#include <sstream>

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
    std::string s = "Test the sstream object\n...";
    std::istringstream is(s);
    func(is);
    return 0;
}