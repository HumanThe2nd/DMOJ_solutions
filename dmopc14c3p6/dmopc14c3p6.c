// DMOPC '14 Contest 3 P6 - Not Enough Time!
// By: Dan Shan
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
	int n,t;
	scanf("%d %d",&n,&t);
	long long dp[t+1];
	for(int i=0;i<=t;i++)dp[i]=0;
	int p1[n],v1[n],p2[n],v2[n],p3[n],v3[n];
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&p1[i],&v1[i],&p2[i]);
		scanf("%d %d %d",&v2[i],&p3[i],&v3[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=t;j>=0;j--){
			if(j+p1[i]<=t) dp[j+p1[i]]=max(dp[j+p1[i]],v1[i]+dp[j]);
			if(j+p2[i]<=t) dp[j+p2[i]]=max(dp[j+p2[i]],v2[i]+dp[j]);
			if(j+p3[i]<=t) dp[j+p3[i]]=max(dp[j+p3[i]],v3[i]+dp[j]);
		}
	}
	printf("%lld\n",dp[t]);
}
