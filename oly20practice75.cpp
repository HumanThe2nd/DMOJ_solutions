// Bob's Lights Game
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int I,N,J,c=0;
  scanf("%d %d %d",&I,&N,&J);
  vector<int> diff,psa;
  for(int i=0;i<I;i++) diff.push_back(0);
  for(int i=0;i<J;i++){
    int xi,xf,k;
    scanf("%d %d %d",&xi,&xf,&k);
    xi--;
    diff[xi]+=k;
    diff[xf]-=k;
  }
  psa.push_back(diff[0]);
  for(int i=1;i<I;i++)psa.push_back(psa[i-1]+diff[i]);
  for(auto x:psa){
    if(x<N)c++;
  }
  printf("%d %s",c,"\n");
}
