#include <algorithm>
#include <iostream>
#include <string>

std::string reverseManual(std::string s) {
  int left = 0, right = s.length() - 1;
  while (left < right) {
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    left++;
    right--;
  }
  return s;
}

std::string reverseSTL(std::string s) {
  std::reverse(s.begin(), s.end());
  return s;
}

int main() {
  std::string input;
  std::cout << "Enter a string: ";
  std::getline(std::cin, input);

  std::string manual = reverseManual(input);
  std::string stl = reverseSTL(input);

  std::cout << "Original: " << input << "\n";
  std::cout << "Manual:   " << manual << "\n";
  std::cout << "STL:      " << stl << "\n";
  std::cout << "Match:    " << (manual == stl ? "yes" : "no") << "\n";
}
