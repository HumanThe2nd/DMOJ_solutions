// TSS Club Fair 2017 Problem B
// by: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
int main() {
  vector<double> dl;
  double N,Q,i1,i2,d=0;
  scanf("%lf",&N);
  scanf("%lf",&Q);
  for(int i=0;i<N;i++){
    scanf("%lf",&i1);
    scanf("%lf",&i2);
    i1 = abs(i1);
    i2 = abs(i2);
    dl.push_back(pow(i1*i1+i2*i2,0.5));
  }
  sort(dl.begin(),dl.end());
  for(int i=0;i<Q;i++){
    scanf("%lf",&i1);
    d = upper_bound(dl.begin(),dl.end(),i1)-dl.begin();
    cout << d << "\n";
    d=0;
  }
}
