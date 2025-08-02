/*
COCI '08 Contest 1 #2 Ptice
Author: Dan Shan
Date: 2025-08-02
1. Count total correct answers for each using modulus
2. Find maximum among the 3 and output
3. Output the names with counters equal to m (in alphabetic order)
TC: O(N)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,a=0,b=0,g=0;
    char s[101],as[]="ABC",bs[]="BABC",gs[]="CCAABB";
    scanf("%d %s",&n,s);
    for(int i=0;i<n;++i){
        a+=s[i]==as[i%3];
        b+=s[i]==bs[i%4];
        g+=s[i]==gs[i%6];
    } int m=a;
    if(b>m) m=b;
    if(g>m) m=g;
    printf("%d\n",m);
    if(a==m) puts("Adrian");
    if(b==m) puts("Bruno");
    if(g==m) puts("Goran");
}
