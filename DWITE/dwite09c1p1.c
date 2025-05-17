/*
DWITE '09 R1 #1 - iProfits
Author: HumanThe2nd
Date: 2025-03-18
res = ceil( 0.99n / 700 )
res = ceil( n/693 )
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    for(int i=5;i-->0;){
        double n;
        scanf("%lf",&n);
        n=n/693+0.999999;
        printf("%d\n",(int)n*1000);
    }
}
