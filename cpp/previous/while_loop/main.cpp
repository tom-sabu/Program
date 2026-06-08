#include <iostream>

int main() {
    int count = 1, sum = 0, n;
    std::cout << "Enter a number : ";
    std::cin >> n;
    while (count <= n) {
        sum += count;
        count++;
    }
    std::cout << "sum of count 1-" << n << ": " << sum << std::endl;
    return 0;
}