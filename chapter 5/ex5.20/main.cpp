#include <iostream>

int main() {
    std::string cur, prev;
    bool flag = true;
    while (std::cin >> cur) {
        if (cur == prev) {
            flag = false;
            break;
        }
        prev = cur;
    }
    if (!flag)
        std::cout << "The word is " << cur << std::endl;
    else
        std::cout << "No duplicated word" << std::endl;
    return 0;
}