#include <iostream>

void reset(int &x) {
    x = 0;
}

int main() {
    int x;
    while (std::cin >> x) {
        reset(x);
        std::cout << x << std::endl;
    }
    return 0;
}