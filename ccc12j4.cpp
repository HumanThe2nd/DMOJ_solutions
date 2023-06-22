#include <iostream>
#include <cmath>
int main() {
  int K;
  // ascii "A" = 65, ascii "Z" = 90
  std::string msg;
  std::string letter2;
  int change;
  int letter;
  std::cin >> K;
  std::cin >> msg;
  for(int i = 1; i < msg.length()+1;i++){
    letter = int(msg[i-1]);
    change = letter-(K+i*3)%26;
    if(change >= 65){
      letter2 = change;
      std::cout << letter2;
    }
    else{
       letter2 = 91 - (65 - change);
       std::cout << letter2;
    }
}
}
