/*
DMOPC '15 Contest 1 P6 - Lelei and Contest
Author: Dan Shan
Date: 2025-12-26
Lazy segment tree (range sum update & query)
Modulo all updates values by 'm' when querying
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
#define BS (1 << 24)
char buf[BS];
char *ptr = buf;
inline void buff() {
    fread(buf, 1, BS, stdin);
    ptr = buf;
}
inline int scan() {
    int x = 0;
    while (*ptr < '0') ++ptr;
    while (*ptr >= '0') {
        x = x * 10 + (*ptr - '0');
        ++ptr;
    }
    return x;
}
int m;
int a[200001], t[800004], lazy[800004]; // t_size = 4 * a_size
static inline void b(int ai, int l, int r){ // build
    if(l == r) {
        t[ai] = a[l] % m; return;
    }
    int mid = (l + r) >> 1;
    b(ai << 1, l, mid);
    b((ai << 1) | 1, mid + 1, r);
    t[ai] = (t[ai << 1] + t[(ai << 1) | 1]) % m;
}
inline void p(int ai, int l, int r) {
    if (!lazy[ai]) return;
    t[ai] += (r - l + 1) * lazy[ai];
    if (t[ai] >= m) t[ai] %= m;
    if (l != r) {
        lazy[ai << 1] += lazy[ai];
        lazy[(ai << 1) | 1] += lazy[ai];
    }
    lazy[ai] = 0;
}

static inline void u(int ai, int l, int r, int ul, int ur, int val){
    if (l > ur || r < ul) return;
    p(ai, l, r);
    if (l >= ul && r <= ur) {
        lazy[ai] += val;
        p(ai, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    u(ai << 1, l, mid, ul, ur, val);
    u((ai << 1) | 1, mid + 1, r, ul, ur, val);
    t[ai] = (t[ai << 1] + t[(ai << 1) | 1]) % m;
}

static inline int q(int ai, int l, int r, int ql, int qr){
    if (l > qr || r < ql) return 0;
    p(ai, l, r);
    if (l >= ql && r <= qr) return t[ai];
    int mid = (l + r) >> 1;
    return (q(ai << 1, l, mid, ql, qr)
          + q((ai << 1) | 1, mid + 1, r, ql, qr)) % m;
}
int main(){
    buff();
    m = scan(); // mod
    int N = scan(), Q = scan();
    for(int i = 0; i < N; ++i) a[i] = scan();
    b(1, 0, N - 1);
    while(Q--){
        int ti = scan();
        if(ti == 1){ // update
            int ul = scan(), ur = scan(), val = scan();
            u(1, 0, N - 1, --ul, --ur, val % m);
            continue;
        } // query 
        int ql = scan(), qr = scan();
        printf("%d\n",q(1, 0, N - 1, --ql, --qr));
    }
}
