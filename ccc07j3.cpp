// CCC '07 J3 - Deal or No Deal Calculator
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0,offer;
  unordered_map<int,int> m;
  m[1]=100; m[2]=500; m[3]=1000;
  m[4]=5000; m[5]=10000; m[6]=25000;
  m[7]=50000; m[8]=100000;
  m[9]=500000; m[10]=1000000;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    m[in]=0;
  }
  for(int i=1;i<=10;i++) c+=m[i];
  c/=10-n;
  scanf("%d",&offer);
  if(c>offer) cout<<"no deal";
  else cout <<"deal";
}
