/*
CCC '07 S5 - Bowling for Numbers
Theory: 
Start from left and use dynamic programming to store maximum value for 
maximum points at each pin and its minimum bowls in another array
if the current bowls is already full then stop bowling from that spot.
Use prefix sum array to find value of different bowls in O(1) time each
*/
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,w;
		scanf("%d %d %d",&n,&k,&w);
		int dp[n+1],psa[n+1];
		dp[0]=0; psa[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&psa[i]);
			dp[i]=0;
			psa[i]+=psa[i-1];
		}
		for(int i=0;i<k;i++){ // each ball
			for(int j=n;j>=0;j--){ // each starting index
			int wi=n-j;
			if(w<n-j) wi=w;
			int ni=dp[j]+psa[j+wi]-psa[j];
			for(int ii=j+wi;ii<=n;ii++){
				if(ni>dp[ii]) dp[ii]=ni; 
				else break;
			}
			}
		}
		printf("%d\n",dp[n]);
	}
}
