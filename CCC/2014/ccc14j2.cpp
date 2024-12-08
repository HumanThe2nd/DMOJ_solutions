#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int n,A = 0,B=0;
  string inp;
  cin >> n >> inp;
  for(int i = 0; i < n;i++){
    if(inp.substr(i,1) == "A") A++;
    else B++;
  }
  if(A > B) cout << "A";
  else if(A==B) cout << "Tie";
  else cout << "B";
}
