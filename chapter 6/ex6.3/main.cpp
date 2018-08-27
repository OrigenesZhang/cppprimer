#include <iostream>
#include <stdexcept>

int fact(int val) {
    if (val < 0)
        throw std::runtime_error("The factorial of negative number is undefined");
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int main() {
    int val;
    while (std::cin >> val) {
        if (val == -1) break;
        try {
            std::cout << fact(val) << std::endl;
        } catch (std::runtime_error &err) {
            std::cout << err.what() << std::endl;
        }
    }
    return 0;
}