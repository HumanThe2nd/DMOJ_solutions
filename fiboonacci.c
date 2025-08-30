/*
Fibonacci Sequence
Author Dan Shan
Date: 2025-08-29

Matrix exponentiation
Referenced: https://www.geeksforgeeks.org/dsa/matrix-exponentiation
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
typedef unsigned long long ll;
ll m=1e9+7;
void mult(ll a[2][2], ll b[2][2]){ // matrix multiplication
    ll c[2][2];
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0])%m; // matrix multiplication 
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1])%m;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0])%m;
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1])%m;

    a[0][0] = c[0][0]; a[0][1] = c[0][1];
    a[1][0] = c[1][0]; a[1][1] = c[1][1];
}
void pow(ll res[2][2], ll a[2][2], ll e){
    res[0][0] = 1; res[0][1] = 0;
    res[1][0] = 0; res[1][1] = 1;

    ll temp[2][2];
    while(e){
        if(e & 1) mult(res, a);
        temp[0][0] = a[0][0]; temp[0][1] = a[0][1];
        temp[1][0] = a[1][0]; temp[1][1] = a[1][1];
        mult(a, temp);
        e >>= 1;
    }
    a=res;
}
ll f(ll n){
    if(n<2) return n; // base
    ll res[2][2], b[2][2]={{1, 1}, {1, 0}};
    pow(res, b, n - 1); // exoponentiate
    return res[0][0] % m;
}
int main() {
    unsigned long long n;
    scanf("%llu",&n);
    printf("%llu\n",f(n));
}
