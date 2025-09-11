/*
VPEX P0 - Pizza
Author: Dan Shan
Date: 2025-09-11
1. Divide x by N
2. Mod x by N
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int x,n;
    scanf("%d %d",&x,&n);
    printf("%d %d\n",x/n, x%n);
}
