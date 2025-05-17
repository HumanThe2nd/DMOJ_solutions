/*
DWITE '09 R6 #4 - Time for Change
Author: HumanThe2nd
Date: 2025-03-30
Unbounded knapsack assuming perfect weight is possible
*/
#include <stdio.h>
int main() {
    int t=5;
    while(t--){
        int n,m;
        scanf("%d %d",&m,&n);
        int dp[m+1]; dp[0]=0;
        for(int i=1;i<=m;i++) dp[i]=2e9;
        for(int i=0;i<n;i++){
            int ai;
            scanf("%d",&ai);
            for(int j=0;j+ai<=m;j++){
                if(dp[j]+1<dp[j+ai]) dp[j+ai]=dp[j]+1;
            }
        }
        printf("%d\n",dp[m]); // assumes always possible
    }
}
