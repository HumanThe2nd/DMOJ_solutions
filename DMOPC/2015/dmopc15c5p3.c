/*
DMOPC '15 Contest 5 P3 - All Your Base
Author: Dan Shan
Date: 2025-07-09
1. append e to the front of the chain
2. convert 2nd rightmost integer to base of rightmost and remove the last element
3. Repeat until 1 element remains
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int e,n;
    scanf("%d %d",&e,&n); ++n;
    int a[n]; a[0]=e;
    for(int i=1;i<n;++i) scanf("%d",&a[i]);
    while(--n){
        int ai=0,p=1;
        while(a[n-1]){ // base conversion
            ai+=(a[n-1]%10)*p;
            a[n-1]/=10;
            p*=a[n];
        }
        a[n-1]=ai;
    }
    printf("%d\n",a[0]);
}
