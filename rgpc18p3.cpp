// RGPC '18 P3 - Chocolate Day
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t;
  scanf("%d %d",&n,&t);
  vector<int> psa;
  for(int i=0;i<n;i++){
    psa.push_back(0);
  }
  for(int i=0;i<t;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    psa[a-1]+=c;
    psa[b]-=c;
  }
  vector<int> diff;
  diff.push_back(psa[0]);
  for(int i=1;i<n;i++)diff.push_back(diff[i-1]+psa[i]);
  int m,c=0,res=0,l=0; 
  scanf("%d",&m);
  for(int i=0;i<n;i++){
  c+=diff[i];
  while(c>m){
    c-=diff[l];
    l++;
  }
  res = max(res,i-l+1);
  }
  printf("%d",res);
}
