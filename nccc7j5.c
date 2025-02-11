/*
Mock CCC '19 Contest 2 J5 - Tudor Drinks Even More Tea
Author: Dan Shan
Date: 2025-02-10
Sieve to store pairty of each prime (or zero for numbers with a repeated factors)
Mobius inversion formula to compute the number of co-prime pairs using parity
Compute all pairs up to (B,D) and subtract the pairs less than (A,C)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
long long max(long long a,long long b) {
    return a>b?a:b;
}
long long s[10000001],p[10000001]; // sieve and mobius
int main() {
    long long a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    long long m=max(b,d)+1;
    for(long long i=1;i<m;i++) p[i]=1;
    for(long long i=2;i<m;i++){
        if(s[i]) continue; // composite
        for(long long j=i;j<m;j+=i){
        s[j]=1; p[j]*=-1;
        }
        for(long long j=i*i;j<m;j+=i*i) p[j]=0;
    }
    long long res=0;
    for(long long i=1;i<m;i++){
        res+=(long long)p[i]*(b/i-(a-1)/i)*(d/i-(c-1)/i); // mobius inversion
    }
    printf("%lld\n",res);
}
