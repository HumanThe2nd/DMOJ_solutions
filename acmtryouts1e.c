// ACM U of T Tryouts C1 E - Foxling Feeding Frenzy
// Author: Dan Shan
// Date: 2024-10-25
// Dp with each cell by each cookie
#include <stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        long long a[n],ai;
        for(int i=0;i<n;i++){
            scanf("%lld %lld",&ai,&a[i]);
            a[i]-=ai; m-=ai;
        }
        if(m<0){
            printf("0\n");
            continue;
        }
        long long dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            } 
        dp[0][0]=1;
        for(int i=1;i<=n;i++){ // for each extra cookie
            for(int j=0;j<=m;j++){
                for(int k=0;k<=min(j,a[i-1]);k++){
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        printf("%lld\n",dp[n][m]);
    }
}
