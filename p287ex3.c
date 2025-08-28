/*
BlueBook - Min
Author: Dan Shan
Date: 2025-08-27
1. Store minimum
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    double mn,ai;
    scanf("%d %lf",&n,&mn);
    while(--n){
        scanf("%lf",&ai);
        if(ai<mn) mn=ai;
    }
    printf("%.2lf\n",mn);
}
