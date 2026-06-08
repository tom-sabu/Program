#include <iostream>

int main() {
    std::cout << "Enter a number (1-10):" << std::endl;
    int num;
    std::cin >> num;
    if (num == 10)
        std::cout << "ha ha" << std::endl;
    else if (num  < 10 && num > 5)
        std::cout << "he he" << std::endl;
    else
        std::cout << "hu hu" << std::endl;
    return 0;
}