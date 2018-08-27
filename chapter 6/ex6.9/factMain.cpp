#include <iostream>
#include <stdexcept>
#include "Chapter6.h"

int main() {
    int x;
    while (std::cin >> x) {
        try {
            std::cout << fact(x) << std::endl;
        } catch (std::runtime_error &err) {
            std::cout << err.what() << std::endl;
        }
    }
    return 0;
}