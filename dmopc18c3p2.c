// DMOPC '18 Contest 3 P2 - Bob and French Class
// By: Dan Shan
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int a[100004],b[100004],dp[3][100005];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        dp[2][i]=dp[1][i-1]+a[i];
        dp[1][i]=dp[0][i-1]+a[i];
        dp[0][i]=max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]))+b[i];
    }
    m = dp[0][n];
    m = max(m,dp[1][n]);
    m = max(m,dp[2][n]);
    printf("%d\n",m);
}
