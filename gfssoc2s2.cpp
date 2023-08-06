// GFSSOC '15 Fall S2 - Hearth
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,t;
  map<string, int> m;
  cin >> n >> t;
  for(int i=0;i<n;i++){
  string s;
  int c;
  cin >> s >> c;
  m[s] = c;
  }
  auto i = m.begin();
  while(i!=m.end()){
    auto j = i;
    while(j!=m.end()){
      auto k =j;
      while(k!=m.end()){
        if(i->second+j->second+k->second<=t&&i!=j&&i!=k&&j!=k){
        cout << i->first<<" "<<j->first<<" "<<k->first<<"\n";}
        k++;
      }
      j++;
    }
    i++;
  }
}
