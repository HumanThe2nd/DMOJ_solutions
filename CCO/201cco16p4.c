/*
CCO '16 P4 - O Canada
Author: Dan Shan
Created: July 26, 2026

for each grid:
    iterate every row except the last
        iterate all cols except the last
            - set the current cell to W if not already
            - adjust the 3 cells right/down appropriately
    store hash of the grid (unordered_set saves time)
return number of distinct grids

** I used bitmask instead of hash here since the relevant cells are limited to 2 * N = 20 
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
static inline void strscan(char *s) {
    while (*ptr <= ' ') ++ptr;
    while (*ptr > ' ') *s++ = *ptr++;
    *s = '\0';
}
int t[1 << 22], r, c;
int main() {
    buff();
    int n = scan(), g = scan();
    while(g--){
        int a[n][n]; // convert to boolean grid
        for(int i = 0; i < n; ++i){
            char si[12];
            strscan(si);
            for(int j = 0; j < n; ++j) a[i][j] = (si[j] == 'W' ? 0 : 1);
        }
        for(int i = 1; i < n; ++i){ // reduce to lexico-min
            for(int j = 1; j < n; ++j){
                if(a[i - 1][j - 1]){
                    a[i - 1][j - 1] = 0; a[i - 1][j] ^= 1;
                    a[i][j - 1] ^= 1;  a[i][j] ^= 1;
               }
            }
        }
        int h = 0;
        for(int i = 0; i < n; ++i) h = (h << 1) + a[i][n - 1];
        for(int i = 0; i < n; ++i) h = (h << 1) + a[n - 1][i];
        c += t[h];
        ++t[h];
    }
    printf("%d\n", c);
}
