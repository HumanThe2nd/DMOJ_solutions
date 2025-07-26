/*
The Mirror
Author: Dan Shan
Date: 2025-07-25
1. build prime sieve
2. Count composites in ranges
*/
#include <stdio.h>
int sieve[501];
int main() {
    int n;
    scanf("%d",&n);
    int l[n],r[n],m=1;
    for(int i=0;i<n;++i){
        scanf("%d %d",&l[i],&r[i]);
        if(r[i]>m) m=r[i];
    } sieve[1]=1;
    for(int i=2;i*i<=m;++i){
        for(int j=(i<<1);j<=m;j+=i) sieve[j]=1;
    }
    for(int i=0;i<n;++i){
        int c=0;
        for(int j=l[i];j<r[i];++j) c+=!sieve[j];
        printf("%d\n",c);
    }
}
