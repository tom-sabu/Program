#include <iostream>
#include <random>

int main() {

  std::cout << "\n"
             "        Welcome!\n\n"
             "Guess a number between 1 and 10.\n"
             "You have 5 chances.\n\n"
             "\033[33mYellow  = very close\033[0m\n"
             "\033[32mGreen = close\033[0m\n"
             "\033[31mRed    = far\033[0m\n\n";

  int rand_num, ch = 10, guess;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(1, 10);
  rand_num = distrib(gen);

  while (ch) {
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    int diff = std::abs(rand_num - guess);
    if (diff) {
      float close_in_per = (diff * 100.0f / rand_num);
      if (close_in_per > 100) close_in_per = 100;
      int color = 3 - static_cast<int>((3.0f / 100.0f * close_in_per));
      std::printf("\033[3%dmThis diff!\033[0m Try again\n", color);
      ch--;
      std::cout << ch << " chance left!\n";
      continue;
    }
    std::cout << "well done, you have gussed it right!!\n";
    break;
  }

  return 0;
}
