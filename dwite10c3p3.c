// DWITE '10 R3 #3 - Dominos Tiling
// Author: Dan Shan
#include <stdio.h>
#define s(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	for(int t=0;t<5;t++){
		int n; s(n);
		if(n&1){
			printf("0\n"); 
			continue;
		}
		int dp[n+1];
		dp[0]=1; dp[1]=1; dp[2]=3;
		for(int i=4;i<=n;i+=2){
			dp[i]=dp[i-2]*4-dp[i-4];
			dp[i]%=1000000;
		}
		printf("%d\n",dp[n]);
	}
}
