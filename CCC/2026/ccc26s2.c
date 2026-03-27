/*
CCC '26 S2 - Beams of Light
Author: Dan Shan
Date: Mar 27, 2026

Approach: Prefix-sum arrays
1. Mark changes in array
2. Build PSA 
3. For each query check whether the value is non-zero
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
int a[500002];
int main(){
    buff();
    int n = scan() + 1, l = scan(), q = scan();
    for(int i = 0; i < l; ++i){ // build array
        int ai = scan(), bi = scan();
        ++a[ai - bi < 1 ? 1 : ai - bi]; // left bound
        --a[ai + bi + 1 > n ? n : ai + bi + 1]; // right bound
    }
    for(int i = 2; i <= n; ++i) a[i] += a[i - 1]; // build PSA
    while(q--){
        int qi = scan();
        puts(a[qi] ? "Y" : "N");
    }
}
