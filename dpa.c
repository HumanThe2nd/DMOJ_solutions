// Educational DP Contest AtCoder A - Frog 1
// By: Dan Shan 
// Frog DP
#include<stdio.h>
int min(int a,int b){return a>b?b:a;}
int abs(int a){return a?a:-a;}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],dp[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		dp[i]= 2e9;
	}
	dp[0]=0;
	for(int i=0;i<n-1;i++){
		dp[i+1]=min(dp[i+1],dp[i]+abs(a[i]-a[i+1]));
		if(i<n-2)
			dp[i+2]=min(dp[i+2],dp[i]+abs(a[i]-a[i+2]));
	}
	printf("%d\n",dp[n-1]);
}
