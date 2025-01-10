/*
DMOPC '20 Contest 6 P1 - Tug of War
Author: Dan Shan
Date: 2025-12-09
Prefix sum of the array twice concatenated
Binary search PSA for each simulated rotation
*/
#include <stdio.h>
typedef long long ll;
ll scan() { // input template
    ll a=0;
    char c=getchar();
    while('0'<=c&&c<='9') a=a*10+c-'0',c = getchar();
    return a;
}
ll abs(ll a){
    return a<0?-a:a;
}
int main(){
    ll n=scan();
    long long a[n],psa[2*n+1];
    for(ll i=0;i<n;i++) {
        a[i]=scan();
        psa[i+1]=a[i]+psa[i];
    }
    for(ll i=0;i<n;i++) psa[n+i+1]=psa[n+i]+a[i];
    for(ll i=0;i<n;i++){
        ll l=i,r=n+i;
        ll m=2e9;
        while(l<=r){
            ll mid=l+((r-l)>>1);
            ll lr=psa[n+i]-psa[mid],rl=psa[mid]-psa[i];
            ll d=abs(lr-rl);
            if(d<m) m=d;
            if(lr<rl) r=mid-1;
            else l=mid+1;
        }
        printf("%d%c",m,i==n-1?'\n':' ');
    }
}
