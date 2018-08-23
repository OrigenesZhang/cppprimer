#include <iostream>

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (std::cin >> ch) {
        if (ch == 'a') {
            aCnt++;
        } else if (ch == 'e') {
            eCnt++;
        } else if (ch == 'i') {
            iCnt++;
        } else if (ch == 'o') {
            oCnt++;
        } else if (ch == 'u') {
            uCnt++;
        }
    }
    std::cout << "Number of vowel a: \t" << aCnt << std::endl;
    std::cout << "Number of vowel e: \t" << eCnt << std::endl;
    std::cout << "Number of vowel i: \t" << iCnt << std::endl;
    std::cout << "Number of vowel o: \t" << oCnt << std::endl;
    std::cout << "Number of vowel u: \t" << uCnt << std::endl;
    return 0;
}