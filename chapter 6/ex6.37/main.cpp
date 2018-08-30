#include <string>

using StrArr = std::string[10];

// Type alias form
StrArr &func1();

// Trailing form
auto func2() -> std::string(&)[10];

std::string str[10] = {};
// decltype
decltype(str) &func3();

int main() {
    return 0;
}