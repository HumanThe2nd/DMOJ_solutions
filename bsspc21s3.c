/*
BSSPC '21 S3 - James's Egirl Discord Status
Author: Dan Shan
Date: 2025-06-08
Dyanamic programming: max subarray mod k up to each index
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
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
long long dp[1000001];
int main(){
    buff();
    long long n=scan(),k=scan(),psa[n+1],m=0;
    psa[0]=0;
    for(int i=0;i<n;++i){
        long long ai=scan();
        psa[i+1]=psa[i]+ai;
        if(i+1<k) continue;
        long long af=psa[i+1]-psa[i-k+1]+dp[i-k];
        if(af>0) dp[i]=af;
        if(af>m) m=af;
    }
    printf("%lld\n",m);
}
