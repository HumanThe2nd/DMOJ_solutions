// CCC 2014 J3 - Double Dice
// by: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int n, ar, dr, a = 100, d = 100; 
  cin >> n;
  for(int i = 0; i < n;i++){
    cin >> ar >> dr;
    if(ar > dr) d -= ar;
    else if(dr > ar) a -= dr;
  }
  cout << a << "\n" << d;
}
