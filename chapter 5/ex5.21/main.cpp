#include <iostream>

int main() {
    std::string cur, prev;
    bool flag = true;
    while (std::cin >> cur) {
        if (cur == prev && cur[0] >= 'A' && cur[0] <= 'Z') {
            flag = false;
            break;
        }
        prev = cur;
    }
    if (!flag)
        std::cout << "The word is " << cur << std::endl;
    else
        std::cout << "No duplicated word starting with upper case letters" << std::endl;
    return 0;
}