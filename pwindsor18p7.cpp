// VMSS Pre-Windsor P7 - Going Back to the Definitions
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v;
  for(int i=0;i<n;i++){
    string in;
    cin >> in;
    v.push_back(in);
  }
  sort(v.begin(),v.end(),[](string x, string y){return x+y > y+x;});
  for(auto x: v) cout<<x;
}
