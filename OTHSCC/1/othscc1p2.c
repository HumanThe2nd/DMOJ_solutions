// OTHS Coding Competition 1 (Mock CCC) J2 - Wand Selection
// By: Dan Shan
#include<stdio.h>
int main(){
int n,m=0,s=0,a;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&a);
if(a>m) m = a;
s+=a;
}
printf("%d\n",(s-m)/(n-1));
}
