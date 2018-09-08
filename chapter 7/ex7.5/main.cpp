#include <iostream>

struct Person {
    std::string name;
    std::string address;

    std::string getName() const;

    std::string getAddress() const;
};

std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

//The functions should be defined as const because they are read-only and should allow const instances of Person object
//to use these functions

int main() {
    return 0;
}