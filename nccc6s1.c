/*
Mock CCC '19 Contest 1 S1 - Pusheen's Report Card
Author: Dan Shan
Date: 2025-08-26
Calculate average
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    double c=0;
    for(int i=0;i<n;++i){
        int ai;
        scanf("%d",&ai);
        c+=ai;
    }
    c/=n;
    printf("%.1lf\n",c);
}
