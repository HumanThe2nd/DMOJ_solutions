/*
Mock CCC '14 J1 - Love Overdose
Author: Dan Shan
Date: 2025-08-19
Casework
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a,b,r;
    scanf("%d %d %d",&a,&b,&r);
    if(a>r) puts("Bob overdoses on day 1.");
    else if(a+(b<<1)>(r<<1)) puts("Bob overdoses on day 2.");
    else puts("Bob never overdoses.");
}
