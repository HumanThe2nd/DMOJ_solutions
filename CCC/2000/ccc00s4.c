/*
CCC '00 S4 - Golf
Author: Dan Shan
Date: Sep 13, 2026

Maintain dp for fastest path to each position from 0 to the hole
For each new club:
    For each position:
        update if this club is optimal
TC: O(N * #_of_clubs)
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
int main() {
    buff();
    int n = scan(), m = scan(), a[m], dp[n + 1];
    for(int i = 0; i < m; ++i) a[i] = scan();
    for(int i = 1; i <= n; ++i) dp[i] = 2e9;
    dp[0] = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int cst = dp[j] + 1, pf = j + a[i];
            if(pf <= n && cst < dp[pf]) dp[pf] = cst;
        }
    }
    if(dp[n] < 2e9) printf("Roberta wins in %d strokes.\n", dp[n]);
    else puts("Roberta acknowledges defeat.");
}
