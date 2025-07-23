/*
Mock CCC '18 Contest 1 J1 - A String Problem
Author: Dan Shan
Date: 2025-07-22
1. (optional) shortcut cases where last digit isn't 9
2. brute force each number greater than n
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n;
    scanf("%d",&n);
    if(n%10<9) return !printf("%d\n",n+1); // shortcut
    for(int i=n+1;i<11111111;++i){ // brute force
        int ai=i,f=1;
        while(ai){
            if(!(ai%10)) {
                f=0; break;
            }
            ai/=10;
        }
        if(f) return !printf("%d\n",i);
    }
}
