/*
Mock CCC '19 Contest 1 J5 - Pusheen Designs a Sushi Boat
Author: Dan Shan
Date: 2025-05-19
dp[i][j] = ways to make boat of size j with sashimi(s) if value i
*/
#include <stdio.h>
typedef long long ll;
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
ll dp[1001][1001],a[1001];
int main(){
    buff();
    int n=scan(),k=scan();
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        int ai=scan();
        a[ai]++;
    }
    for(int i=1;i<=n;++i){
        dp[i][0]=dp[i-1][0];
        for(int j=1;j<=k;++j){
            dp[i][j]=(dp[i-1][j]+a[i]*dp[i-1][j-1])%998244353;
        }
    }
    printf("%lld\n",dp[n][k]);
}
