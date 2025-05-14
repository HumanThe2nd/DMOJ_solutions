// Educational DP Contest AtCoder B - Frog 2
// By: Dan Shan
// Modified frog DP
#include<stdio.h>
int min(int a,int b){return a>b?b:a;}
int abs(int a){return a?a:-a;}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n],dp[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		dp[i]= 2e9;
	}
	dp[0]=0;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<=k;j++){
		if(i<n-j)
			dp[i+j]=min(dp[i+j],dp[i]+abs(a[i]-a[i+j]));
		}
	}
	printf("%d\n",dp[n-1]);
}
