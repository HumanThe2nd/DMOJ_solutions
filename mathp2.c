/*
A Math Contest P2 - Subsequence Sum
Author: Dan Shan
Date: 2025-05-22
Each element may be used 2*(n-1) times
therefore, answer = sum_of_all_elements*2^(n-1)
Note: use modulus when computing sums and the exponents of 2s as well as taking their product
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int main(){
    buff();
    int n=scan(),mod=1e9+7;
    long long res=0,m=1;
    int ai=scan();
    res+=ai;
    for(int i=1;i<n;i++) {
        ai=scan();
        res=(res+ai)%mod;
        m=(m<<1)%mod;
    }
    res=res*m%mod;
    printf("%lld\n",res);
}
