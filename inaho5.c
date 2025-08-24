/*
Inaho V
Author: Dan Shan
Date: 2025-08-24
1. Input as unsigned long longs
2. Take sum of positive numbers
3. Return the negative sum 
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    unsigned long long res=0;
    scanf("%d",&n);
    while(n--){
        long long ai;
        scanf("%lld",&ai);
        res-=ai;
    }
    if(res) printf("-%llu\n",res);
    else puts("0");
}
