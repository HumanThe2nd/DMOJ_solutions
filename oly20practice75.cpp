// Bob's Lights Game
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n,m,c=0;
  scanf("%d %d",&n,&m);
  vector<int> diff,psa;
  for(int i=0;i<n;i++) diff.push_back(0);
  for(int i=0;i<m;i++){
    int s,e;
    scanf("%d %d",&s,&e);
    s--;
    diff[s]++;
    diff[e]--;
  }
  psa.push_back(diff[0]);
  for(int i=1;i<n;i++)psa.push_back(psa[i-1]+diff[i]);
  for(auto x:psa){
    if(x%2==1)c++;
  }
  printf("%d %s",c,"\n");
}
