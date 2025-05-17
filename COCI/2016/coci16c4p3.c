/*
COCI '16 Contest 4 #3 Kas
Author: HumanThe2nd
Date: 2025-03-31
DP: Max money each combination
3 states: add, skip, subtract (give to other)
m: max per person with equal split
Res = total - m/2
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int dp[500][100001];
int max(int a, int b){
    return a<b?b:a;
}
int abs(int a){
  return a<0?-a:a;
}
int main() {
    int n,l;
    scanf("%d %d",&n,&l);
    dp[0][l]=l;
    for(int i=1;i<n;i++){
        int ai;
        scanf("%d",&ai); l+=ai;
        dp[i][ai]=max(dp[i][ai],ai); // start with this banknote
        for(int j=0;j<=l;j++){
            if(!dp[i-1][j]) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j]); // skip banknote
            if(j+ai<=l) dp[i][j+ai]=max(dp[i][j+ai],dp[i-1][j]+ai); // give to rich
            dp[i][abs(j-ai)]=max(dp[i][abs(j-ai)],dp[i-1][j]+ai); // give to poor
        }
    }
    printf("%d\n",l-dp[n-1][0]/2);
}
