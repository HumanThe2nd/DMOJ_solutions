/*
Educational DP Contest AtCoder I - Coins
Author: HumanThe2nd
Date: 2025-04-06
Dynamic programming:
number of ways to get more than half heads
update the probability of each combination after adding each coin
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
double dp[3000],res=0;
int main() {
    int n;
    scanf("%d",&n);
    dp[0]=1;
    for(int i=0;i<n;i++) {
        double ai;
        scanf("%lf",&ai);
        for(int j=i+1;j>0;j--){
            dp[j]*=(1-ai);
            dp[j]+=dp[j-1]*ai;
        }
        dp[0]*=(1-ai);
    }
    for(int i=n;i>n/2;i--) res+=dp[i];
    printf("%0.10lf\n",res); // must be precise up to 10^-9
}
