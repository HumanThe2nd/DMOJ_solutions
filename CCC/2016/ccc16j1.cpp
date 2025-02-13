#include <iostream>
#include <cmath>

int main() {
  int W = 0;
  std::string input;
  for (int i = 0; i<6;i++){
    std::cin >> input;
    if(input =="W")
      W++;
  }
  if(W > 4)
    std::cout << 1;
  else if(W > 2)
    std::cout << 2;
    else if(W > 0)
      std::cout << 3;
      else
        std::cout << -1;
}
