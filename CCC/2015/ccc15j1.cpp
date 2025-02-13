#include <iostream>
#include <cmath>

int main() {
  int month;
  int day;
  std::cin >> month;
  std::cin >> day;
  if(month > 2 || (month ==2 && day > 18))
    std::cout << "After";
  else if(month == 2 && day ==18)
      std::cout << "Special";
    else
      std::cout << "Before";
}
