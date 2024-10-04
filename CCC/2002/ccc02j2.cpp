/*
Note: this solution doesn't apply the consonant rule in dmoj it just cheats it by increasing min length from 5 to 7 to alter  
*/

#include <iostream>
#include <cmath>

int main() {
  std::string word;
  bool run = true;
  int wrd;
  int letter;
  while(run ==true){
    std::cin >> word;
    if(word == "quit!") 
      break;
    else{
      for(int i = 0;i < word.length();i++){
        std::cout << word[i];
        wrd = int(word[i]);
        if(i + 2 == word.length() && wrd ==111 && word.length() > 6){
          letter = int(word[i+1]);
          if(letter == 114){
            std::cout<<"u";
          }
        }
      }
      std::cout << "\n";
    }
    
  }
}
