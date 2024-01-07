// Educational DP Contest AtCoder C - Vacation
// By: Dan Shan
#include<stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n],c[n],dp[3][n+1];
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    dp[0][0]=a[0];
    dp[1][0]=b[0];
    dp[2][0]=c[0];
    for(int i=1;i<n;i++){
        dp[0][i]=a[i]+MAX(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=b[i]+MAX(dp[0][i-1],dp[2][i-1]);
        dp[2][i]=c[i]+MAX(dp[0][i-1],dp[1][i-1]);
    }
    int m = MAX(dp[0][n-1],dp[1][n-1]);
    m = MAX(m,dp[2][n-1]);
    printf("%d\n",m);
}
