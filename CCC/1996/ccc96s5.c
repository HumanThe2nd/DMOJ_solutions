/*
CCC '96 S5 - Maximum Distance
Author: Dan Shan
Date: Sep 13, 2026

Iterate all starts in array 1 and binary search the best end-point in array 2
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
    int t = scan();
    while(t--){
        int n = scan(), a[n], a2[n], res = 0;
        for(int i = 0; i < n; ++i) a[i] = scan();
        for(int i = 0; i < n; ++i) a2[i] = scan();
        for(int i = 0; i < n; ++i){
            if(a[i] > a2[i]) continue;
            int l = i, r = n;
            while(l < r){
                int mid = (l + r) >> 1;
                if(a2[mid] >= a[i]) l = mid + 1;
                else r = mid;
            }
            int d = l - i - 1;
            if(d > res) res = d;
        }
        printf("The maximum distance is %d\n", res);
    }
}
