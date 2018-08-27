#include <iostream>

int cnt() {
    static int cnt = 0;
    return cnt++;
}

int main() {
    for (int i = 0; i != 10; i++)
        std::cout << cnt() << std::endl;
    return 0;
}