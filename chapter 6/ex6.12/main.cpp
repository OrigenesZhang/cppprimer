#include <iostream>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        swap(a, b);
        std::cout << a << ' ' << b << std::endl;
    }
    return 0;
}