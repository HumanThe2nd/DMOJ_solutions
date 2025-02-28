/*
DMOPC '16 Contest 3 P1 - Leading Basic Shots
Author: HumanThe2nd
Date: 2025-02-27
subtract n2 if infront,
otherwise add it
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,n2;
    char s[8];
    scanf("%d %s %d",&n,s,&n2);
    if(s[0]=='I') printf("%d\n",n-n2);
    else printf("%d\n",n+n2);
}
