/*
SAC '22 Code Challenge 1 P1 - That Teacher
Author: Dan Shan
Date: 2025-07-29
Result = C - (N * M)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,m,c;
    scanf("%d %d %d",&n,&m,&c);
    printf("%d\n",c-n*m);
}
