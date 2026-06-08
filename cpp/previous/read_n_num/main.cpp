#include <iostream>

int main() {
    int value, sum = 0;
    std::cout << "Enter a number: ";
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "sum of all the value entered: " << sum << std::endl;
}