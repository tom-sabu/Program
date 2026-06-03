#include <iostream>
using namespace std;

int main() {
  char op;
  int num1, num2;
  
  cout << "Enter operator : +, -, *, / : ";
  cin >> op;

  cout << "Enter two operands : ";
  cin >> num1 >> num2;

  switch(op) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
      break;

    case '-':
      cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
      break;

    case '*':
      cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
      break;

    case '/':
      cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
      break;

    default:
      cout << "Error! oprator is not correct.\n";
      break;
  }

  return 0;
}
