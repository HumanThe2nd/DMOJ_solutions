// Lucky Balls
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,k,s=0;
  scanf("%d %d %d %d",&a,&b,&c,&k);
  if(k>=a){s+=a;k-=a;}
  else {s+=k;k=0;}
  if(k>=b)k-=b;
  else k=0;
  if(k>=c){k-=c;s-=c;}
  else {s-=k;k=0;}
  printf("%d",s);
}
