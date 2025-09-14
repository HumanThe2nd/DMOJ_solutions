/*
Mock CCC '20 Contest 2 S1 - Arithmetic Hybercube
Author: Dan Shan
Date: 2025-09-13
Sort the array
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize("Ofast")
int cmp(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    printf("%d", a[0]);
    for(int i = 1; i < n; ++i) printf(" %d",a[i]);
    putchar('\n');
}
