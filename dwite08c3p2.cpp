#include <iostream>
#include <list>
#include <vector>
using namespace std; 
int main() {
  int c=0,wc=0;
  string line,word;
  for(int i=0;i<5;i++){
  getline(cin,line);
  for(auto x: line){
    if(isalpha(x)==false){
      if(c > 3){
        wc++;
      }
      c = 0;
    }
    else c++;
  }
  if(c>3) wc++;
  cout << wc<< "\n";
  wc = 0;
  c = 0;
  }
}
