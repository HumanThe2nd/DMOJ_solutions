// DMOPC '22 Contest 5 P2 - Absolutely Even
// By: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
using v = vector<ll>;
int main() {
  int n;
  vector<int> arr;
  scanf("%d",&n);
  if(n%4==1){
    for(int i=1;i<n+1;i+=2){
      if(i%4==3) cout << i <<" ";
      else cout << -i << " ";
    }
    for(int i=n-1;i>1;i-=2){
      if(i%4==0) cout << i <<" ";
      else cout << -i << " ";
    }
  }
  else if(n%2==1){
    for(int i=1;i<n+1;i+=2){
      if(i%4==3) cout << -i <<" ";
      else cout << i << " ";
    }
    for(int i=n-1;i>1;i-=2){
      if(i%4==0) cout << -i <<" ";
      else cout << i << " ";
    }
  }
  else{
    for(int i=1;i<n+1;i++){
      if(i%4==1) arr.push_back(i);
      else if(i%4==2) arr.push_back(-i);
      else if(i%4==3) arr.insert(arr.begin(),-i);
      else arr.insert(arr.begin(),i);
    }
    for(auto x:arr){
      cout <<x<<" ";
    }
  }
  //cout << endl;
}
