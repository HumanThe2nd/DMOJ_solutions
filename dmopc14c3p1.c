// DMOPC '14 Contest 3 P1 - Not Enough Users!
// By: Dan Shan
// trivial exponential functions 
#include<stdio.h>
#include <math.h>
int main(){
int n,k,d;
scanf("%d %d %d",&n,&k,&d);
printf("%d\n",(int)(n*pow(k,d)));
}
