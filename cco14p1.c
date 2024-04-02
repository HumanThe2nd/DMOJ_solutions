// CCO '14 P1 - Troyangles
// By: Dan Shan
// start from bottom move up counting triangle stacks
#include <stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int main() {
    int n,c=0;
    scanf("%d",&n);
    int dp[n][n];
    for(int i=0;i<n;i++){
        getchar_unlocked();
        for(int j=0;j<n;j++){
            char ch = getchar_unlocked();
            dp[i][j] = ch=='#';
            c+=dp[i][j];
        }
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<n-1;j++){
            int t=min(dp[i][j],dp[i][j-1]);
            t = min(t,dp[i][j+1]);
            if(dp[i-1][j]){
                dp[i-1][j]=t+1;
                c+=t;
            }
        }
    }
    printf("%d\n",c);
}
