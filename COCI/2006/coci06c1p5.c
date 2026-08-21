/*
COCI '06 Contest 1 #5 Bond
Author: Dan Shan
Created: August 20

Problem: Assign each column to match distinct rows so the product is minimal 

Aprroach (Bitmask DP):
- dp[mask] = min for that row mask
- For each mask, transition each column to the next row
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
#define BS (1 << 23)
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
int a[21][20];
double dp[1 << 20];
int main() {
    buff();
    int n = scan();
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < n; ++j) a[i][j] = scan();
    }
    dp[0] = 100.0;
    for(int mask = 1; mask < (1 << n); ++mask){
        int i = __builtin_popcount(mask);
        for(int mf = mask; mf; mf ^= mf & -mf){ // column i (only choose from valid bits)
            int j = __builtin_ctz(mf);
            double vf = a[i][j] / 100.0 * dp[mask ^ (1 << j)];
            if(vf > dp[mask]) dp[mask] = vf; // update if optimal 
        }
    }
    printf("%lf\n",dp[(1 << n) - 1]);
}
