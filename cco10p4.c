// CCO '10 P4 - Computer Purchase Return
// Author: Dan Shan
// multilayer dyanimic programming
// for each layer check each element with each previous weight to find 
// maximum value for each weight at each layer
// if max at 5th layer is 0 then it is impossible else print the maximum
// if it is not possible it means a component is missing or the budget is insufficent
// time complexity: O(t*n*b)
#include<stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
	int t,n,b;
	scanf("%d %d",&t,&n);
	int c[t][n],v[t][n],l[t];
	for(int i=0;i<t;i++) l[i]=0;
	for(int i=0;i<n;i++){
		int ci,vi,ti;
		scanf("%d %d %d",&ci,&vi,&ti);
		ti--; c[ti][l[ti]] = ci; 
		v[ti][l[ti]] = vi; l[ti]++;
	}
	for(int i=0;i<t;i++) if(!l[i]) return printf("-1\n")*0;
	scanf("%d",&b);
	int dp[t+1][b+1];
	for(int i=0;i<=t;i++) 
		for(int j=0;j<=b;j++) dp[i][j]=0;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=b;j++){
			dp[i][j] = dp[i-1][j];
			for(int k=0;k<l[i-1];k++){
				if(j>=c[i-1][k])
					dp[i][j] = max(dp[i][j], dp[i-1][j-c[i-1][k]]+v[i-1][k]);
			}
		}
	}
	printf("%d\n",dp[t][b]);
}
