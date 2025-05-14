/*
Educational DP Contest AtCoder T - Permutation
Author: Dan Shan
Date: 2025-05-14
Time Complexity: O(N^2 / 2) -> O(N^2) 
dp[position][number] = number of paths
'<' -> add all paths to numbers below 
'>' -> add all paths to numbers above 
psa[position] = all valid paths ending at "position"
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int dp[3001][3001],p[3002];
const long long m=1e9+7;
int main(){
    int n;
    char s[3001];
    dp[1][1]=1;
    scanf("%d %s",&n,s);
    for(int i=2;i<=n;++i){
        p[0]=0;
        for(int j=1;j<=i;++j) p[j]=(p[j-1]+dp[i-1][j])%m;
        for(int j=1;j<=i;++j){
            if(s[i-2]=='<') dp[i][j]=p[j-1]; // add paths to all combinations below
            else {
                dp[i][j]=(p[i-1]-p[j-1]+m)%m; // add paths to all numbers above
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;++i) res=(res+dp[n][i])%m; // add paths of all final values
    printf("%d\n",res);
}
