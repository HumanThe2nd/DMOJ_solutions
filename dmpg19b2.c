/*
DMPG '19 B2 - Rectangular Molecules
Author: Dan Shan
Date: 2025-07-16
Hard Code 2 cases: a and c are both less or both greater than the others
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if((a>b&&a>d&&c>b&&c>d)||(a<b&&a<d&&c<b&&c<d)) puts("trans");
    else puts("cis");
}
