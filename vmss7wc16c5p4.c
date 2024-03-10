// VM7WC '16 #5 Silver - Jayden Eats Chocolate
// By: Dan Shan
// Unbounded knapsack
#include <stdio.h>
int main() {
    int n,a,b,c;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    int dp[n+1];
    for(int i=0;i<=n;i++)dp[i]=-1;
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(dp[i]==-1) continue;
        if(i+a<=n&&dp[i]+1>dp[i+a]) dp[i+a]=dp[i]+1;
        if(i+b<=n&&dp[i]+1>dp[i+b]) dp[i+b]=dp[i]+1;
        if(i+c<=n&&dp[i]+1>dp[i+c]) dp[i+c]=dp[i]+1;
    }
    printf("%d\n",dp[n]);
}
