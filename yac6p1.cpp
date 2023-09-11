// Yet Another Contest 6 P1 - No More Separation
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i=1;i<n;i++){
    for(int j=1;j<=n-i;j++){
      if(!m)break;
      printf("%d %d\n",i,j+i);
      m--;
    }
    if(!m)break;
  }
}
