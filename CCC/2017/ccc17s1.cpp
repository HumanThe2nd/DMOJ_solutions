// CCC '17 S1 - Sum Game
// by: Dan Shan
#include <iostream>
#include <list>
#include <vector>
using namespace std; 
int main() {
  int n,inp,day=0,c1=0,c2=0;
  vector<int> t1,t2;
  cin >> n;
  for(int i = 0; i<n;i++){
    cin >> inp;
    t1.push_back(inp);
  }
  for(int i = 0; i<n;i++){
    cin >> inp;
    t2.push_back(inp);
  }
  for(int i = 0;i<n;i++){
    c1+=t1[i];
    c2+=t2[i];
    if(c1 == c2) day = i+1;
  }
  cout << day;
}
