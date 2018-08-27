#include <iostream>

double abs(double x) {
    return x > 0 ? x : -x;
}

int main() {
    double x;
    while (std::cin >> x) {
        std::cout << abs(x) << '\n';
    }
    return 0;
}