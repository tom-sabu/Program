#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cout << "N : ";
  std::cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + n);

  int min = arr[0];
  int max = arr[n - 1];
  double mean = 0;
  double median = 0;

  for (int i = 0; i < n; i++)
    mean += arr[i];
  mean /= n;

  if (n % 2 == 0)
    median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
  else
    median = arr[n / 2];

  std::cout << "Min:    " << min << "\n";
  std::cout << "Max:    " << max << "\n";
  std::cout << "Mean:   " << mean << "\n";
  std::cout << "Median: " << median << "\n";

  delete[] arr;
}
