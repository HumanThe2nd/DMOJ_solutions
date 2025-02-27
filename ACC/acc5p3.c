/*
Another Contest 5 Problem 3 - Cutting Cheese Costs
Author: Dan Shan
Date: 2024-11-28
sort discounts in descneding order
*/
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
   return (*(long long*)b-*(long long*)a);
}
int main() {
    long long n,k;
    scanf("%lld %lld",&n,&k);
    long long a[n],c=0;
    for(int i=0;i<n;i++) {
        long long di;
        scanf("%lld %lld",&a[i],&di);
        c+=a[i];
        a[i]-=di;
    }
    qsort(a,n,sizeof(long long),cmp);
    for(int i=0;i<k;i++) c-=a[i];
    printf("%lld\n",c);
}
