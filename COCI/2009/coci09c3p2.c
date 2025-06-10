/*
COCI '09 Contest 3 #2 Slatkisi
Author: Dan Shan
Date: 2025-06-09
Treat as float to round and revert to int
1. Convert to float divided by 10, 'k' times
2. Round to nearest integer
3. Multiply by 10 'k' times
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize ("Ofast")
int main(){
    double c;
    int k;
    scanf("%lf %d",&c,&k);
    for(int i=0;i<k;++i) c/=10;
    int res=round(c);
    for(int i=0;i<k;++i) res*=10;
    printf("%d\n",res);
}
