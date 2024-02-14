// USACO 2024 January Bronze P2 - Cannonball
// By: Dan Shan
#include <stdio.h>
int main() {
int n,s,p=1,c=0;
scanf("%d %d",&n,&s);
int t[n+1],v[n+1],b[n+1];
for(int i=1;i<=n;i++){
  scanf("%d %d",&t[i],&v[i]);
  b[i]=0;
}
int l=0;
while(1){
  l++;
  if(!t[s]){ // pad
    if(p<0) {
      p*=-1;
      p+=v[s]; }
    else {
      p+=v[s];
      p*=-1;
    }
  }
  else if(p>=v[s]||-p>=v[s]){
    b[s]=1;
  }
  s+=p;
  if(s>n||s<1||l>5e6)break;
}
for(int i=1;i<=n;i++) c+=b[i];
printf("%d\n",c);
}
