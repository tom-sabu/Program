#include <iostream>

void print(double temp, double out_temp, char user_scale, char out_scale) {
  std::cout << temp << " " << user_scale << " "  << " = " << " " << out_temp << " " << out_scale << "\n"; 
}

double to_celsius(double temp, char scale) {
  double out_temp;
  if (scale == 'f') out_temp = (temp - 32) * 5.0/9.0;
  else if (scale == 'k') out_temp = temp - 273.15;
  else if (scale == 'c') out_temp = temp;

  return out_temp;
}

double celsius_to(double temp, char scale) {
  double out_temp;
  if (scale == 'f') out_temp = temp * (9.0 / 5.0) + 32;
  else if (scale == 'k') out_temp = temp + 273.15;
  else if (scale == 'c') out_temp = temp;

  return out_temp;
}

int main() {
  double  temp, out_temp, temp_in_c;
  char user_scale, out_scale;
  std::cout << "Enter magnitude with scale you are gonna use (scales : c = Celsius, f = Fahrenheit, k = Kelvin): ";
  std::cin >> temp >> user_scale;

  std::cout << "Enter the scale you want to convert to (f/k/c): ";
  std::cin >> out_scale; 

  temp_in_c = to_celsius(temp, user_scale);
  out_temp = celsius_to(temp_in_c, out_scale);

  print(temp, out_temp, user_scale, out_scale);

  return 0;
}
