#include <iostream>

bool fact2() {
    int val;
    std::cout << "Input a non-negative integer, negative to exit" << std::endl;
    std::cin >> val;
    if (val < 0) return false;
    int ans = 1;
    while (val)
        ans *= val--;
    std::cout << ans << std::endl;
    return true;
}

int main() {
    while (fact2());
    return 0;
}