/*
Educational DP Contest AtCoder O - Matching
Author: Dan Shan
Created: August 17

Bitmask DP
dp[mask] = # of pathways/combinations
Copied a constant time optimization from another user (my original was slower) 
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
int a[21], dp[1 << 21], mod = 1e9 + 7;
int main() {
    buff();
    int n = scan();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(scan()) a[i] |= 1 << j;
    dp[0] = 1; // base case: no pairs
    for(int mask = 1; mask < (1 << n); ++mask){ // masks
        int i = __builtin_popcount(mask);
        long long rf = 0;
        for(int j = mask & a[i - 1]; j; j &= j - 1){
            rf += dp[mask & ~(j & -j)];
        }
        dp[mask] = rf % mod;
    }
    printf("%d\n", dp[(1 << n) - 1]);
}
