#include <iostream>
#include "Money.hpp"

int main() {
    Money m1(10, 50);
    Money m2(5, 25);

    std::cout << m1.dollars() << std::endl;
    return 0;
}