#include <iostream>

const std::string results[] = {"F", "D", "C", "B", "A", "A++"};

int main() {
    int score;
    std::string grade;
    std::cin >> score;
    if (score < 60) {
        grade = results[0];
    } else {
        grade = results[(score - 60) / 10 + 1];
    }
    std::cout << grade << std::endl;
    return 0;
}