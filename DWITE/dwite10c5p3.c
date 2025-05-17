/*
DWITE '10 R5 #3 - Balancing Act
Author: Dan Shan
Date: 2024-10-08
find max value up to half the sum and subtract double that from the total
*/
#include <stdio.h>
#define abs(a)((a)<(0)?-(a):(a))
int main() {
	for(int ti=0;ti<5;ti++){
    	int n,c=0;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			c+=a[i];
		}
		int dp[c];
		for(int i=0;i<=c/2;i++)dp[i]=0;
		for(int i=0;i<n;i++){
			for(int j=c/2;j>=a[i];j--){
				if(dp[j-a[i]]+a[i]>dp[j]) dp[j]=dp[j-a[i]]+a[i];
			}
		}
		printf("%d\n",c-2*dp[c/2]);
	}
}
