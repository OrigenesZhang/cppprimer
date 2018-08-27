#include <iostream>
#include <stdexcept>
#include "Chapter6.h"

int fact(int val) {
    if (val < 0)
        throw std::runtime_error("The number should be non-negative");
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}