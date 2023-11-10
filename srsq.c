// Static Range Sum Query
// By: Dan Shan
// trivial prefix sum arrays
#include<stdio.h>
int main(){
int n,q;
scanf("%d %d",&n,&q);
int psa[n+1];
for(int i=0;i<n;i++){
int a;
scanf("%d",&a);
psa[i+1] = psa[i] + a;
}
for(int i=0;i<q;i++){
int a,b;
scanf("%d %d",&a,&b);
printf("%d\n",psa[b]-psa[a-1]);
}
}
