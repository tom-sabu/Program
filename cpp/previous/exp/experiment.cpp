#include <iostream>
using namespace std;

int main() {
  int temp = 12, x;
  cout << "enter a num :";
  cin >> x;
  cout << "hai there!" << x << "\n";
  x >>= 3;
  cout << "hai there! " << temp << "  veendum " << x << "\n";
  cout << (temp > x) << "\n";
  return 0;
}
