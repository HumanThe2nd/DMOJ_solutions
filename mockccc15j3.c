/*
Mock CCC '15 J3 - Problem-setting Pandemonium
Author: Dan Shan
Date: 2025-09-09

1. Create viisted array of used problems
2. Count unique problems
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int v[1001];
int main() {
    int n,c=0;
    scanf("%d",&n);
    while(n--){
        int ai;
        scanf("%d",&ai);
        if(!v[ai]) ++c;
        v[ai]=1;
    }
    printf("%d\n",c);
}
