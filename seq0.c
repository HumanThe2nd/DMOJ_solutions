// Summing A Sequence
// Author: Dan Shan
// Date: 2024-09-22
// Dynamic programming approach iteratng taking max (previous value to skip or value from 2 indexes before + val[i]) 
// Note: Account for overflows and avoiding negative starters  
#include <stdio.h>
int main() {
    int n;
	scanf("%d",&n);
	long long dp[n]={},a[n];
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	if(n==1) return printf("%lld\n",a[0]);
	if(a[0]>0) dp[0]=a[0]; 
	if(a[1]>0) dp[1]=a[1];
	if(a[0]>dp[1]) dp[1]=a[0];
	for(int i=2;i<n;i++){
		if(dp[i-1]>0) dp[i]=dp[i-1];
		if(dp[i-2]+a[i]>dp[i]) dp[i]=dp[i-2]+a[i];
	}
	printf("%lld\n",dp[n-1]);
}
