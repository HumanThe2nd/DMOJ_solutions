/*
DMOPC '14 Contest 1 P1 - Median Mark
Author: Dan Shan
Date: 2025-08-03
1. Sort array
2. Odd case: middle number
   Even case: average of middle 2 numbers rounded up
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize("Ofast")
int cmp(const void *a,const void *b){
 return (*(int*)a-*(int*)b);
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    if(n&1) printf("%d\n",a[n>>1]);
    else printf("%d\n",(a[n>>1]+a[(n>>1)-1]+1)>>1);
}
