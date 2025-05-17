/*
COCI '08 Contest 1 #1 Skocimis
Author: HumanThe2nd
Date: 2025-03-23
(Max diff of middle with the 2 outer) - 1
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int res=b-a;
    if(c-b>res) res=c-b;
    printf("%d\n",res-1);
}
