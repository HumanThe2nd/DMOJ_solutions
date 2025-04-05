/*
GFSSOC '14 Winter J3 - Waiting
Author: HumanThe2nd
Date: 2025-04-04
Max on digit differences multiples by 60 for minutes and 3600 for hours
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    char s[9],s2[9];
    scanf("%s %s",s,s2);
    int res=s2[7]-s[7]+(s2[6]-s[6])*10; // seconds
    res+=60*(s2[4]-s[4]+(s2[3]-s[3])*10); // minutes
    res+=3600*(s2[1]-s[1]+(s2[0]-s[0])*10); // hours
    printf("%d\n",res);
}
