#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  string n,x,yes = "YES";
  cin >> n;
  for(int i = 0; i < n.length();i++){
    x = n.substr(i,1);
    if(x != "I" && x != "O" && x != "S" && x != "H" && x != "Z" && x != "X" && x != "N") yes = "NO";
  }
  cout << yes;
}
