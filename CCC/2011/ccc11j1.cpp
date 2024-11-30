#include <iostream>
#include <cmath>

int main() {
  int antennae;
  int eyes;
  std::cin >> antennae;
  std::cin >> eyes;
  if(antennae>=3 && eyes<=4){
    std::cout << ("TroyMartian\n");
  }
  if(antennae<=6 and eyes>=2){
    std::cout << ("VladSaturnian\n");
  }
  if(antennae<=2 and eyes<=3){
    std::cout << ("GraemeMercurian");
  }
}
