#include <iostream>
#include <cmath>

int main() {
  int a = 0;
  int b = 0;
  int inp;
  std::cin >> inp;
  a += inp*3;
  std::cin >> inp;
  a += inp*2;
  std::cin >> inp;
  a += inp*1;
  std::cin >> inp;
  b += inp*3;
  std::cin >> inp;
  b += inp*2;
  std::cin >> inp;
  b += inp*1;
  if(a > b)
    std::cout << "A";
  else if(b > a)
    std::cout << "B";
    else
      std::cout << "T";
}
