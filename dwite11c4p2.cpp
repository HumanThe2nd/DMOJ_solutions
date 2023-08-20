// DWITE '11 R4 #2 - Prime Time
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
vector<int> factor(int n){
  vector<int> out;
  if(n==3){
    out.push_back(3);
    return out;
  }
  while(n%2==0){
    out.push_back(2);
    n/=2;
  }
  for(int i=3;i<=sqrt(n);i+=2){
    while(n%i==0){
    out.push_back(i);
      n/=i;
    }
  }
  if(n>2)out.push_back(n);
  return out;
}
int main(){
  for(int i=0;i<5;i++){
  int n;
  scanf("%d",&n);
  map<int, int> m; // factor, occurences
  for(int i=1;i<n+1;i+=2){
    m[i] = 0;
  }
  m[2]=0;
  for(int i=2;i<n+1;i++){
    vector<int> factors = factor(i);
    for(int x: factors) m[x]++;
  }
  for(int i=1;i<n+1;i++) if(m[i]==0) m.erase(i);
  for(auto x: m) {if(x!=*--m.end()) printf("%d^%d * ",x.first,x.second);
                 else printf("%d^%d\n",x.first,x.second);}
}
}
