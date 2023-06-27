#include <iostream>
#include <cmath>

int main() {
  int temp;
  int K;
  std::cin >> temp;
  K = temp*5-400;
  std::cout << (K) << "\n";
  if(K > 100)
    std::cout << -1;
  else if(K < 100)
    std::cout << 1;
        else
          std::cout << 0;
}
