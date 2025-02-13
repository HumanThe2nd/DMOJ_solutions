#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int happy=0,sad=0;
  string inp;
  getline(cin, inp); 
  for(int i = 2 ;i < inp.length();i++){
    if(inp.substr(i-2,3) == ":-)") happy++;
    if(inp.substr(i-2,3) == ":-(") sad++;
  }
  if(happy == 0 and sad == 0) cout << "none";
  else if (happy>sad) cout << "happy";
  else if(happy==sad) cout << "unsure";
  else cout << "sad";
}
