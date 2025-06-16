// Add Up Apples
// Author: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int print(vector<int> &v,int n,int c){
  if(v.size()!=1){
  printf("%d=",n);
  int s = v.size();
  for(int i=0;i<s-1;i++) printf("%d+",v[i]);
  printf("%d\n",v.back());
  c++;
}
if(v.size()==2)if(abs(v[1]-v[0])<2)printf("total=%d\n",c);
return c;
}
int comb(vector<int> &v,int i, int n, int sum,int c){
  if(n==0) {c=print(v,sum,c);}
  for(int j=i;j<=n;j++){
    v.push_back(j);
    c=comb(v,j,n-j,sum,c);
    v.pop_back();
  }
  return c;
}
int main(){
  int n;
  vector<int> v;
  scanf("%d",&n);
  comb(v,1,n,n,0);
}
