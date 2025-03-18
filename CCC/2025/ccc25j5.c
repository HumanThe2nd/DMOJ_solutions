/*
CCC '25 J5 - Connecting Territories
Author: HumanThe2nd
Date: 2025-02-26
Dynamic programming:
For every cell make add the minimum of the 2-3 cells below it
use 2 by C grid to save memory
Time Complexity: O(R*C)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    long long r,c,m,l,mi=1;
    scanf("%lld %lld %lld",&r,&c,&m);
    if(c==1){ // special case, not needed on ccc grader
        for(int i=1;i<m;i++){
            mi+=i%m+1;
        }
        return printf("%lld\n",mi)*0;
    }
    long long a[2][c]; // alternate between 2 layers to avoid
    for(long long i=1;i<c;i++) a[1][i]=0;
    for(l=0;l<r;l++){
        long long li=(l+1)&1; // last dimension
        for(long long i=0;i<c;i++){
            long long ai=a[li][i];
            if(i&&a[li][i-1]<ai) ai=a[li][i-1]; 
            if(i<c-1&&a[li][i+1]<ai) ai=a[li][i+1];
            a[l&1][i]=ai+mi;
            mi++;
            if(mi>m) mi=1;
        }
    }
    long long min=2e9; l++;
    for(long long i=0;i<c;i++){
        if(a[l&1][i]<min) min= a[l&1][i];
    }
    printf("%lld\n",min);
}
