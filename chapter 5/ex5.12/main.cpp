#include <iostream>

int main() {
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, lineCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    bool flag = false;
    char ch;
    while (std::cin.get(ch)) {
        switch (ch) {
            case 'a':
            case 'A':
                aCnt++;
                flag = false;
                break;
            case 'e':
            case 'E':
                eCnt++;
                flag = false;
                break;
            case 'i':
                if (flag) fiCnt++;
            case 'I':
                iCnt++;
                flag = false;
                break;
            case 'o':
            case 'O':
                oCnt++;
                flag = false;
                break;
            case 'u':
            case 'U':
                uCnt++;
                flag = false;
                break;
            case ' ':
                spaceCnt++;
                flag = false;
                break;
            case '\t':
                tabCnt++;
                flag = false;
                break;
            case '\n':
                lineCnt++;
                flag = false;
                break;
            case 'f':
                // Here fff is only counted once instead of twice
                flag ? ffCnt++, flag = false : flag = true;
                break;
            case 'l':
                if (flag) flCnt++;
                flag = false;
                break;
            default:
                flag = false;
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
    std::cout << "Number of substring ff: \t" << ffCnt << std::endl;
    std::cout << "Number of substring fl: \t" << flCnt << std::endl;
    std::cout << "Number of substring fi: \t" << fiCnt << std::endl;
    return 0;
}