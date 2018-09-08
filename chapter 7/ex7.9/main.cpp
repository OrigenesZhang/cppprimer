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

std::istream &read(std::istream &in, Person &person) {
    in >> person.name >> person.address;
    return in;
}

std::ostream &print(std::ostream &out, const Person &person) {
    out << person.name << ' ' << person.address;
    return out;
}

int main() {
    return 0;
}