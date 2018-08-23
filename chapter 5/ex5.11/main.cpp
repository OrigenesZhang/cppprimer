#include <iostream>

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, lineCnt = 0;
    char ch;
    while (std::cin.get(ch)) {
        switch (ch) {
            case 'a':
            case 'A':
                aCnt++;
                break;
            case 'e':
            case 'E':
                eCnt++;
                break;
            case 'i':
            case 'I':
                iCnt++;
                break;
            case 'o':
            case 'O':
                oCnt++;
                break;
            case 'u':
            case 'U':
                uCnt++;
                break;
            case ' ':
                spaceCnt++;
                break;
            case '\t':
                tabCnt++;
                break;
            case '\n':
                lineCnt++;
                break;
            default:;
        }
    }
    std::cout << "Number of vowel a: \t" << aCnt << std::endl;
    std::cout << "Number of vowel e: \t" << eCnt << std::endl;
    std::cout << "Number of vowel i: \t" << iCnt << std::endl;
    std::cout << "Number of vowel o: \t" << oCnt << std::endl;
    std::cout << "Number of vowel u: \t" << uCnt << std::endl;
    std::cout << "Number of spaces: \t" << spaceCnt << std::endl;
    std::cout << "Number of tabs: \t" << tabCnt << std::endl;
    std::cout << "Number of new lines: \t" << lineCnt << std::endl;
    return 0;
}