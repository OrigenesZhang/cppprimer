#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int main() {
    std::vector<int (*)(int, int)> vec = {add, sub, mul, div};
    int a, b;
    while (std::cin >> a >> b && b) {
        for (const auto &it : vec) {
            std::cout << it(a, b) << '\n';
        }
        std::cout << std::endl;
    }
    return 0;
}