// DMOPC '16 Contest 4 P2 - Systests
// By: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
using v = vector<ll>;
int main() {
  int b,p,f,t=0; // p:points; b & f: input counts
  ll s,e,w; // start & end & failed ints
  v S,E,P,W; // Start & End & Point & Wrong vectors
  scanf("%d",&b);
  for(int i=0;i<b;i++){
    scanf("%lld %lld %d",&s,&e,&p);
    S.push_back(s);
    E.push_back(e);
    P.push_back(p);
  }
  scanf("%d",&f);
  for(int i = 0;i<f;i++){
    scanf("%lld",&w);
    W.push_back(w);
  }
  sort(W.begin(),W.end());
  for(int i = 0;i<b;i++){
    if(lower_bound(W.begin(),W.end(),S[i])-W.begin() == upper_bound(W.begin(),W.end(),E[i])-W.begin()) 
      t+= P[i];
  }
  cout << t << "\n";
}
