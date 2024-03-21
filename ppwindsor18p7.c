// VMSS Pre-Pre-Windsor P7 - Magical Bribery
// By: Dan Shan
// unbounded knapsack with weights as index of values. (one indexed)
#include<stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
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
    int v[n],w[n],dp[n+1];
    for(int i=0;i<n;i++){
        v[i]=scan();
        dp[i]=0; w[i]=i+1;
    } dp[n]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            if(w[j]<=i)dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
        }
    }
    printf("%d\n",dp[n]);
}
