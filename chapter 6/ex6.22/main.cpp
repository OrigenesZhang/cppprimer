#include <iostream>

void swap(int* &a, int* &b) {
    int *t = a;
    a = b;
    b = t;
}

int main() {
    int *p1, *p2;
    int a, b;
    while (std::cin >> a >> b) {
        p1 = &a;
        p2 = &b;
        swap(p1, p2);
        std::cout << *p1 << ' ' << *p2 << std::endl;
    }
    return 0;
}