// UCC Coding Competition '20 P4 - Bubble Tea
// By: Dan Shan
#include<stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main(){
    int n=scan();
    int a[n],dp[n+1]; dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=2e9; a[i-1]=scan();
    }
    for(int i=0;i<n;i++){
        if(dp[i]+a[i]<dp[i+1]) dp[i+1]=dp[i]+a[i];
        if(i>n-2) continue;
        int t=dp[i]+a[i]+a[i+1]-min(a[i],a[i+1])/4;
        if(t<dp[i+2]) dp[i+2]=t;
        if(i>n-3) continue;
        t=dp[i]+a[i]+a[i+1]+a[i+2];
        t-=min(min(a[i],a[i+1]),a[i+2])/2;
        if(t<dp[i+3]) dp[i+3]=t;
    }
    printf("%d\n",dp[n]);
}
