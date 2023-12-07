// CCC '15 J5 - π-day
// By: Dan Shan
// gave up recursion and used 2d arrays to track combinations
#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    int dp[n+1][k+1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            if(!j||j>i) dp[i][j]=0;
            else if (j==1||i==j) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    printf("%d\n", dp[n][k]);
}
