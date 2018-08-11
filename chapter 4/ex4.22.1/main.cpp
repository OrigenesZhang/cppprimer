#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int grade;
    string finalgrade;
    cin >> grade;
    finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade > 75) ? "pass" : "low pass";
    cout << finalgrade << endl;
    return 0;
}