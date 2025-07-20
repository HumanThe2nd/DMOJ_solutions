/*
COCI '09 Contest 1 #2 Domino
Author: Dan Shan
Date: 2025-07-20
Brute force + arithmetic series
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,c=0;
    scanf("%d",&n);
    for(int i=0;i<=n;++i){
        c+=2*i+(i+((double)n+i+1)/2)*(n-i);
    }
    printf("%d\n",c);
}
