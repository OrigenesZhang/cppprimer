#include <iostream>

int max(int a, const int *p) {
    return a > *p ? a : *p;
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        std::cout << max(a, &b) << std::endl;
    }
    return 0;
}