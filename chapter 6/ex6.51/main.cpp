#include <iostream>

void f() {
    std::cout << "The function takes in no argument" << std::endl;
}

void f(int x) {
    std::cout << "The function takes in an integer " << x << std::endl;
}

void f(int x, int y) {
    std::cout << "The function takes in two integers " << x << " and " << y << std::endl;
}

void f(double x, double y = 3.14) {
    std::cout << "The function takes in two doubles " << x << " and " << y << std::endl;
}

int main() {
//    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}