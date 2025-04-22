/*
Educational DP Contest AtCoder N - Slimes
Author: HumanThe2nd
Date: 2025-04-22
DP: [left_bound][right_bound]
Find max between every 2 slimes and move up
Time Complexity: O(n^3)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
long long psa[401],dp[401][401];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&psa[i]);
        psa[i]+=psa[i-1];
    }
    for(int i=1;i<n;++i){
        for(int l=1;l<=n-i;++l){
            long long mn=2e18,r=i+l;
            for(int k=l+1;k<=r;k++){
                if(dp[l][k-1]+dp[k][r]<mn) mn=dp[l][k-1]+dp[k][r];
            }
            dp[l][r]=mn+psa[r]-psa[l-1];
        }
    }
    printf("%lld\n",dp[1][n]);
}
