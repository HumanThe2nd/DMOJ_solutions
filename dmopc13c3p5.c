// DMOPC '13 Contest 3 P5 - A Romantic Dinner
// By: Dan Shan
// multidimension bounded knapsack
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
    int m,u,r;
    scanf("%d %d %d",&m,&u,&r);
    int v[r],w[r],w2[r],dp[r+1][m+1][u+1];
    for(int i=0;i<r;i++) {
        scanf("%d %d %d",&v[i],&w[i],&w2[i]);
    }
    int i,j,k;
    for(i=0;i<=r;i++){
        for(j=0;j<=m;j++){
            for(k=0;k<=u;k++){
                if(!i||!j||!k) dp[i][j][k]=0;
                else if(w[i-1]<=j&&w2[i-1]<=k)
                    dp[i][j][k]=max(dp[i-1][j][k],v[i-1]+dp[i-1][j-w[i-1]][k-w2[i-1]]);
                else dp[i][j][k]= dp[i-1][j][k];
            }
        }
    }
    printf("%d\n",dp[r][m][u]);
}
