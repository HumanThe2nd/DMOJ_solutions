/*
Educational DP Contest AtCoder X - Tower
Author: Dan Shan
Date: Nov 1, 2026

Observation: plates should be placed in non-descending order of strength + weight

Approach: 
sort by descending weight + strength for bottom to top
for each index
    for each weight limit
        update the max of the new weight limit if higher value
        (weight limit decreases as blocks are added)
return max value of any weight limit
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize("Ofast")
#define BS (1 << 23)
typedef long long ll;
char buf[BS];
char *ptr = buf;
inline void buff() {
    fread(buf, 1, BS, stdin);
    ptr = buf;
}
static inline int scan() {
    int x = 0, neg = 0;
    while (*ptr < '0') {neg = (*ptr == '-'); ++ptr;}
    while (*ptr >= '0' && *ptr <= '9') {
        x = x * 10 + (*ptr - '0');
        ++ptr;
    }
    if(neg) return -x;
    return x;
}
int cmp(const void *a, const void *b) {
    const int *rowA = (const int *)a;
    const int *rowB = (const int *)b;
    return (rowA[0] + rowA[1] < rowB[0] + rowB[1]) - (rowA[0] + rowA[1] > rowB[0] + rowB[1]);
}
ll dp[100001];
int main() {
    buff();
    int n = scan();
    int a[n][3], W = 1, S = 1;
    for(int i = 0; i < n; ++i) {
        a[i][0] = scan(); // weight
        if(a[i][0] > W) W = a[i][0];
        a[i][1] = scan(); // strength
        if(a[i][1] > S) S = a[i][1];
        a[i][2] = scan(); // value
    }
    ll res = 0;
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n; ++i) {
        for(int j = a[i][0]; j <= S + W; ++j) {
            int sf = a[i][1] < j - a[i][0] ? a[i][1] : j - a[i][0]; // new weight = min(si, j - wi)
            if(dp[j] + a[i][2] > dp[sf]) dp[sf] = dp[j] + a[i][2];
        }
    }
    for(int i = 0; i <= S; ++i) if(dp[i] > res) res = dp[i];
    printf("%lld\n", res);
}
