/*
COCI '17 Contest 4 #1 Rasvjeta
Author: Dan Shan
Date: 2025-09-26
1. Fill in already covered cells
2. For each uncovered cell, place a light so it's covered in the corner (mark the next 2k cells after it as well)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int v[1001];
int main() {
    int n, m, k, c = 0;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        int ai;
        scanf("%d", &ai); --ai;
        v[ai] = 1;
        for(int i = 1; i <= k; ++i){
            if(ai + i >= n) break;
            v[ai + i] = 1;
        }
        for(int i = 1; i <= k; ++i){
            if(ai - i < 0) break;
            v[ai - i] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(v[i]) continue;
        for(int j = 0; j <= 2*k; ++j){
            if(i + j >= n) break;
            v[i + j] = 1;
        } ++c;
    }
    printf("%d\n",c);
}
