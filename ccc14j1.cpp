#include <iostream>
#include <cmath>

int main() {
  int a1;
  int a2;
  int a3;
  std::cin >> a1;
  std::cin >> a2;
  std::cin >> a3;
  if(a1 + a2 + a3 != 180)
    std::cout << "Error";
  else if(a1 ==a2 && a2==a3)
    std::cout << "Equilateral";
    else if(a1 == a2 || a2 == a3|| a1 == a3)
      std::cout << "Isosceles";
      else
        std::cout << "Scalene";
}
