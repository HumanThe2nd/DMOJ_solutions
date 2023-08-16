// DMOPC '21 Contest 4 P2 - Festive Groups
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;
  scanf("%d",&n);
  vector<int> s;
  for(int i=0;i<n;i++){
    int j;
    scanf("%d",&j);
    s.push_back(j);
  }
  sort(s.begin(),s.end());
  int lim = *--s.end();
  vector<bool> f (lim+1,true);
  for(auto x: s){
    if(f[x]){
      c++;
      for(int i=x;i<=lim;i+=x) f[i] = false;
    }
  }
  cout<<c<<endl;
}
