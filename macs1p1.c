/*
Max's Anger Contest Series 1 P1 - Hunger Bar
Author: Dan Shan
Date: 2025-09-08

1. Subtract time from the min of max health and eaten apples
2. Output the max of the result and 0
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(b < a) a = b;
    a -= c;
    if(a < 0) a = 0;
    printf("%d\n",a);
}
