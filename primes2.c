/*
Primes 2
Author: Dan Shan
Date: 2025-01-01
Segmented sieve
- sieve of eratosthenes
- only the relevenat interval is stored the rest are ignored
*/
#include <stdio.h>
#include <stdbool.h>
long long scan() {
    long long num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
bool a[5000001];
int main() {
    long long n=scan(),m=scan();
    if(n==1) a[0]=1; // 1 is not prime
    for(long long i=2;i*i<=m;i++){
        long long s=((n+i-1)/i)*i; // first multiple of i that is >=n
        if(s==i) s+=i; // skip the prime itself
        for(long long j=s;j<=m;j+=i){
            a[j-n]=1; // not prime
        }
    }
    for(long long i=n;i<=m;i++){
        if(!a[i-n]) printf("%lld\n",i);
    }
}
