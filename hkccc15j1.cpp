#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n,a,b;
  a = b = 0;
  vector<string> alice, bob;
  string inp,am,bm;
  cin >> n;
  // inputing alice
  for(int i = 0;i<n;i++){
    cin >> inp;
    alice.push_back(inp);
  } // inputing bob
  for(int i = 0;i<n;i++){
    cin >> inp;
    bob.push_back(inp);
  }
  // driver code:
  for(int i = 0; i < alice.size();i++){
    am = alice[i];
    bm = bob[i];
    if((am =="rock" && bm == "scissors")||(am == "scissors" && bm == "paper")|| (am == "paper" && bm == "rock")) a++;
    else if(bm != am) b++;
  }
  cout << a << " " << b;
}
