/*
ICPC PACNW 2016 A - Alphabet
Author: HumanThe2nd
Date: 2025-04-30
Dynamic Programming
26 - longest increasing subsequence
States: LIS -> dp[index][character]
Time Complexity: O(N*26) -> O(N)
*/
#include <stdio.h>
#include <string.h>
#pragma GCC optimize ("Ofast")
int dp[51][26];
int main() {
    char s[51];
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;++i){
        int ai=s[i]-'a',mi=0;
        for(int j=0;j<26;++j){
            if(dp[i+1][j]<dp[i][j]) dp[i+1][j]=dp[i][j];
        }
        for(int j=0;j<ai;++j){
            if(mi<dp[i][j]) mi=dp[i+1][j];
        }
        if(dp[i+1][ai]<mi+1) dp[i+1][ai]=mi+1;
    }
    int m=0;
    for(int i=0;i<26;++i) if(dp[l][i]>m) m=dp[l][i];
    printf("%d\n",26-m);
}
