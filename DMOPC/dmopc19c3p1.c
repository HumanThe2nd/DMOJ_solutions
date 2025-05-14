/*
DMOPC '19 Contest 3 P1 - Mode Finding
Author: Dan Shan
Date: 2024-12-26
Increment all elements by 1e5 to avoid negatives
use frequency array to find optimal elements in order
*/
#include <stdio.h>
int nscan() {
    int n=0, a=0;
    char c=getchar_unlocked();
    if(c=='-')n=1,c=getchar_unlocked();
    while('0'<=c&&c<='9')a=a*10+c-'0',c=getchar_unlocked();
    return n?-a:a;
}
int v[200001];
int main() {
    int n=nscan(),m=0;
    for(int i=0;i<n;i++){
        int ai=nscan();
        ai+=100000;
        v[ai]++;
        if(v[ai]>m) m=v[ai];
    } int s=0; // whitespace
    for(int i=0;i<200001;i++){
        if(v[i]!=m) continue;
        if(!s) s=1;
        else putchar_unlocked(' ');
        printf("%d",i-100000);
    } putchar_unlocked('\n');
}
