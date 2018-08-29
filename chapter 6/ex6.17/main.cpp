#include <iostream>

bool hasUpper(const std::string &s) {
    for (auto it : s) {
        if (it >= 'A' && it <= 'Z')
            return true;
    }
    return false;
}

void toLower(std::string &s) {
    for (auto &it : s) {
        if (it >= 'A' && it <='Z')
            it = it - 'A' + 'a';
    }
}

int main() {
    std::string s;
    while (std::cin >> s) {
        if (hasUpper(s)) {
            toLower(s);
            std::cout << s << std::endl;
        } else {
            std::cout << "No upper case letters" << std::endl;
        }
    }
    return 0;
}