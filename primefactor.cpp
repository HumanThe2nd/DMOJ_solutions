// Prime Factorization
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
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int num;
    scanf("%d",&num);
    vector<int> res= factor(num);
    int s = res.size();
    for(int i=0;i<s-1;i++) cout<<res[i]<<" ";
    cout<<res.back()<<"\n";
  }
}
