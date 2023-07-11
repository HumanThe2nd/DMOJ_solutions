// The Cosmic Era P2 - Uneven Sand
// by: Dan Shan
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
using namespace std; 
using ll = long long;
int main() {
  bool ok = false;
  string inp;
  ll n,min = 1,max=2000000002;
  while(ok == false){
    n = (max+min)/2;
    cout << ll(n) << "\n" << flush;
    cin >> inp;
    if(inp == "OK") break;
    else if(inp == "FLOATS") max = min + (max-min)/2;
    else min += (max-min)/2;
  }
}
