#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int grade;
    string finalgrade;
    cin >> grade;
    if (grade > 90) {
        finalgrade = "high pass";
    } else if (grade < 60) {
        finalgrade = "fail";
    } else if (grade > 75) {
        finalgrade = "pass";
    } else {
        finalgrade = "low pass";
    }
    cout << finalgrade << endl;
    return 0;
}