#include <iostream>

const std::string results[] = {"F", "D", "C", "B", "A", "A++"};

int main() {
    int score;
    std::string grade;
    std::cin >> score;
    grade = results[score < 60 ? 0 : (score - 60) / 10 + 1];
    std::cout << grade << std::endl;
    return 0;
}