/*
CCO '07 P2 - Snowflakes
Author: Dan Shan
Created: July 22, 2026

Cache visited hashes and count # of unique hashes
For each snowflake:
    Use Booth's algorithm for lexicographical minimal rotation
    Use Booth's on the reverse as well
    Take the minimum of the 2 sequences above
    Hash the rotation
    If it's a duplicate: exit as twin snowflakes
If end reached without dupes: none are alike

** I implemented hash with linear probing manually which is overkill (I'm just deranged)
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
struct snowflake{
    int a[6], h;
};
struct snowflake t[1000004];
int v[1000004], mod = 1000003;
int main(){
    buff();
    int n = scan();
    while(n--){
        int a[6], b[6], mn[6], mn2[6], c0 = 0, c1 = 1, k = 0;
        for(int i = 0; i < 6; ++i) a[i] = scan(), b[5 - i] = a[i];
        while(c0 < 6 && c1 < 6 && k != 6){ // Booth's alg on cw
            if(a[(c0 + k) % 6] == a[(c1 + k) % 6]) ++k;
            else{
                if(a[(c0 + k) % 6] < a[(c1 + k) % 6]) c1 += k + 1;
                else c0 += k + 1;
                if(c0 == c1) ++c1; // prevent collision
                k = 0;
            }
        }
        int hi = 0, hi2 = 0; // compute hash
        if(c1 < c0) c0 = c1; // smallest rotation
        for(int i = 0; i < 6; ++i){
            mn[i] = a[(c0 + i) % 6];
            hi = (hi * 131 + mn[i]) % mod; 
        }

        c0 = 0; c1 = 1; k = 0;
        while(c0 < 6 && c1 < 6 && k != 6){ // Booth's alg on ccw
            if(b[(c0 + k) % 6] == b[(c1 + k) % 6]) ++k;
            else{
                if(b[(c0 + k) % 6] < b[(c1 + k) % 6]) c1 += k + 1;
                else c0 += k + 1;
                if(c0 == c1) ++c1; // prevent collision
                k = 0;
            }
        }
        if(c1 < c0) c0 = c1; // smallest rotation
        for(int i = 0; i < 6; ++i){
            mn2[i] = b[(c0 + i) % 6];
            hi2 = (hi2 * 131 + mn2[i]) % mod; 
        }
        int min = 0; // determine minimal between cw and ccw
        for(int i = 0; i < 6; ++i){
            if(mn2[i] < mn[i]){ min = 1; break;}
            if(mn2[i] > mn[i]) break;
        }

        int h = (min ? hi2 : hi), *res = min ? mn2 : mn; // set minimal
        hi = h;
        while(v[hi]){ // linear probe all adjacent matches
            if(t[hi].h == h){
                int same = 1;
                for(int i = 0; i < 6; ++i) if(t[hi].a[i] != res[i]) same = 0;
                if(same) return !puts("Twin snowflakes found.");
            }
            ++hi;
            if(hi == mod) hi = 0;
        }
        v[hi] = 1;
        t[hi].h = h;
        for(int i = 0; i < 6; ++i) t[hi].a[i] = res[i];
    }
    puts("No two snowflakes are alike.");
}
