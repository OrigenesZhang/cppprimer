#include <iostream>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    std::string s;
    size_t ctr = 1;
    while (std::cin >> s) {
        std::cout << make_plural(ctr++, s) << std::endl;
    }
    return 0;
}