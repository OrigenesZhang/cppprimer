#include <iostream>

int main() {
    std::string judge;
    do {
        std::cout << "Input two strings: " << std::endl;
        std::string s1, s2;
        std::cin >> s1 >> s2;
        if (s1 < s2) std::cout << "The first string is smaller" << std::endl;
        else if (s1 > s2) std::cout << "The second string is smaller" << std::endl;
        else std::cout << "They are equal" << std::endl;
        std::cout << "To continue: (Yes or No)" << std::endl;
        std::cin >> judge;
    } while(judge[0] == 'Y');
    return 0;
}