#include <iostream>
#include <stdexcept>

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        try {
            if (b == 0)
                throw std::runtime_error("The denominator cannot be zero");
            std::cout << a / b << std::endl;
            break;
        } catch (std::runtime_error &err) {
            std::cout << err.what() << '\n' << "Try again? Entry y or n" << std::endl;
            std::string str;
            std::cin >> str;
            if (str[0] == 'n') break;
        }
    }
    return 0;
}