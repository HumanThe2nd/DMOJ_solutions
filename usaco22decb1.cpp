#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
int main() {
  ll n,inp,max=0,c=0,p;
  vector<ll> offers;
  scanf("%lld",&n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&inp);
    offers.push_back(inp);
  }
  sort(offers.begin(), offers.end());
  for(int i = n;i>0;i--){
    if(offers[i]*(n-i) >= max){
      max = offers[i]*(n-i);
      p = offers[i];
    }
  }
  cout << max << " "<< p << "\n";
}
