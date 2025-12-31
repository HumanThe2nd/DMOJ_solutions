/*
APIO '10 P1 - Commando
Author: Dan Shan
Date: 2025-12-26
Problem summary:
- Given array of integers: x, and 3 coefficients: a, b, c
- Let f(x) = ax^2 + bx + c
- Merge elements of x, such that sum of the f(x_i) is maximal

Approach:
- Isolate PSA of the array, reducing problem to CHT
- use CHT for mx + b at each point
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
#define BS (1 << 24)
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
ll a, b, c, p[1000001], dq[2000005], dp[1000001];
ll f(int i, int j) {
    ll t = (p[i] - p[j]);
    return a * t*t + b * t + c;
}
double g(int j, int k) { // slope
    return (double)(dp[k] - dp[j] - b * p[k] + b * p[j] + a * p[k]*p[k] - a * p[j]*p[j]) / (a * 2 * (p[k] - p[j]));
}
int main(){
    buff();
    dq[0] = 0;
    int n = scan(), l = 0, r = 1;
    a = scan(); b = scan(); c = scan();
    for(int i = 1; i <= n; ++i) p[i] = scan() + p[i-1];
    for(int i = 1; i <= n; ++i){ // CHT
        while(r - l > 1 && g(dq[l], dq[l+1]) <= p[i]) ++l;
        dp[i] = dp[dq[l]] + f(i, dq[l]);
        while (r - l > 1 && g(dq[r - 1], i) < g(dq[r - 2], dq[r - 1])) --r;
        dq[r++] = i;
    }
    printf("%lld\n", dp[n]);
}
