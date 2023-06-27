#include <iostream>
#include <cmath>

int main() {
  int a;
  int b;
  int c;
  int d;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  std::cin >> d;
  if((a==8||a==9)&&(d==8||d==9)&&b==c)
    std::cout << "ignore";
  else
    std::cout << "answer";
}
