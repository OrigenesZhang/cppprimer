#include <iostream>

class Account {
public:
    void calculate() {
        amount += amount * interestRate;
    }

    static double rate() {
        return interestRate;
    }

    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;

    static double initRate();

    static constexpr int period = 30;
    double daily_tbl[period];
};

void Account::rate(double r) {
    interestRate = r;
}

double Account::initRate() {
    return 0;
}

double Account::interestRate = initRate();

int main() {
    return 0;
}