// Yet Another Contest 7 P2 - Coprime Grid
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  for(int k=0;k<t;k++){
    bool r=1;
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==1||m==1){ printf("-1\n"); continue;};
    for(int i=0;i<n;i++){
      if(r){
      r=0;
      for(int j=2;j<=m;j++){
        printf("%d ",j+(i*m));
      }
      if((i*m)+m+1>n*m) printf("%d\n",1);
      else printf("%d\n",(i*m)+m+1);
      }
      else{
      r=1;
      if(i==n-1){
      printf("%d ",1);
      for(int j=m;j>1;j--){
      printf("%d ",j+(i*m));
      }
      printf("\n");
      break;
      }
      for(int j=m+1;j>2;j--){
        printf("%d ",j+(i*m));
      }
      printf("%d\n",(i*m)+2);
      }
    }
  }
}
