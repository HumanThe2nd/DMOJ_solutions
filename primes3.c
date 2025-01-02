/*
Primes 3
Author: Dan Shan
Date: 2025-01-02
Miller-Rabin primality test
Uses custom multiplication and exponent methods to prevent overflow
Checks some factors using modulus before resorting to Miller-Rabin
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma GCC optimize ("Ofast")
typedef unsigned long long ll;
ll scan() {
    ll num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
ll multiply(ll a, ll b, ll m){
    ll res=0;
    a%=m;
    while(b){
        if(b&1) res=(res+a)%m;
        a=(a<<1)%m;
        b>>=1;
    }
    return res;
}
ll pow(ll b, ll p, ll m){ // base, power, mod
    ll res=1;
    b%=m;
    while(p){
        if(p&1) res=multiply(res,b,m); // odd number
        b=multiply(b,b,m);
        p>>=1;
    }
    return res;
}
int miller_rabin(ll n, ll a){ // singular check
    ll d=n-1,s=0;
    while(!(d&1)){
        d>>=1; s++;
    }
    ll x=pow(a,d,n);
    if(x==1||x==n-1) return 1;
    for(ll i=0;i<s-1;i++){
        x=multiply(x,x,n);
        if(x==n-1) return 1;
    }
    return 0;
}
int check_prime(ll n, int it){ // Runs Miller-Rabin with different bases 
    if(n==1) return 0; // 1 is not prime
    ll primes[]={2,3,5,7,11,13};
    for(int i=0;i<6;i++){
        if(n==primes[i]) return 1; // definite prime
        if(!(n%primes[i])) return 0; // definite composite
    }
    for(int i=0;i<it;i++){
        ll a=2+rand()%(n-4);
        if(!miller_rabin(n,a)) return 0; // definite composite
    }
    return 1; // possible prime
}
int main() {
    ll t=scan();
    srand(time(NULL));
    while(t--){
        ll ai=scan();
        puts(check_prime(ai,10)?"PRIME":"NOT"); // 10 iterations
    }
}
