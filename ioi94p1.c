// IOI '94 P1 - The Triangle
// By: Dan Shan
#include<stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
	int n;
	scanf("%d",&n);
	int a[n][n],dp[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			scanf("%d",&a[i-1][j]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)dp[i][j]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			int ni=dp[i][j]+a[i][j];
			dp[i+1][j+1]=max(dp[i+1][j+1],ni);
			dp[i+1][j]=max(dp[i+1][j],ni);
		}
	}
	for(int i=0;i<=n;i++)dp[n][n]=max(dp[n][n],dp[n][i]);
	printf("%d\n",dp[n][n]);
}
