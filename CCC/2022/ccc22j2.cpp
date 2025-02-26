#include <iostream>
#include <cmath>

int main() {
  int N;
  int points;
  int fouls;
  int count = 0;
  std::cin >> N;
  for (int i = 0; i<N;i++){
    std::cin >> points;
    std::cin >> fouls;
    if(points*5 -fouls*3 > 40)
      count++;
  }
  if(count == N)
    std::cout << N <<"+";
  else
    std::cout << count;
}
