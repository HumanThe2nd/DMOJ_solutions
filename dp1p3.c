// Longest Increasing Subsequence
// By: Dan Shan
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n],dp[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        dp[i]=1;
    } 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]&&dp[i]+1>dp[j]) dp[j]=dp[i]+1;
        }
    }
    for(int i=0;i<n-1;i++){
        if(dp[i]>dp[n-1]) dp[n-1]=dp[i];
    }
    printf("%d\n",dp[n-1]);
}
