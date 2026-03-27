/*
CCC '26 J1 - Concert Tickets
Author: Dan Shan
Date: Mar 27, 2026
2 cases:
1. (total - purchased) < wanted: not possible
2. otherwise: possible, remaining = total - purchased - wanted
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(b - c < a) return !puts("N");
    printf("Y %d\n", b - c - a);
}
