#include <iostream>
#include <cmath>

int main() {
  int h; 
  int M;
  bool land = false;
  std::cin >> h;
  std::cin >> M;
  for (int i = 1; i < M; i++) {
  if(-6*pow(i,4)+h*pow(i,3)+2*i*i+i <= 0){
    std::cout << "The balloon first touches ground at hour:\n";
    std::cout << i;
    land = true;
    break;
  }
  }
  if(land == false){
    std::cout << "The balloon does not touch ground in the given time.";
  }
}
