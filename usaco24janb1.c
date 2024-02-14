// USACO 2024 January Bronze P1 - Majority Opinion
// By: Dan Shan
#include<stdio.h>
int main() {
int t;
scanf("%d",&t);
for(int ti=0;ti<t;ti++){
  int n,e=1;
  scanf("%d",&n);
  int a[n],h[n+1];
  for(int i=0;i<n;i++) {
    scanf("%d",&a[i]);
    h[i+1]=0;
  }
  if(n==2&&a[0]==a[1]){
      printf("%d\n",a[0]);
      continue;
  }
  for(int i=2;i<n;i++){
    if(a[i-2]==a[i-1]||a[i-2]==a[i])
      h[a[i-2]]=1;
    else if(a[i-1]==a[i])
      h[a[i-1]]=1;
  }
  for(int i=1;i<=n;i++){
    if(h[i]){
      if(!e)printf(" ");
      e=0;
      printf("%d",i);
    }
  }
  if(e)printf("-1");
  printf("\n");
}
}
