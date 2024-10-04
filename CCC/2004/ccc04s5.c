// CCC '04 S5 - Super Plumber
// Author: Dan Shan
// Date: 2024-10-01
// Theory: For each node scan up and down taking the max and store last column in dp array
#include <stdio.h>
int main() {
	while(1){
		int n,m;
		scanf("%d %d",&n,&m);
		if(!n) break;
		char s[n][m+1];
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
			for(int j=0;j<m;j++) if(s[i][j]=='.') s[i][j]='0';
		}
		int dp[n+1][m+1],dp2[n+1][m+1];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) dp[i][j]=-1e8;
		} 
		dp[n-1][0]=s[n-1][0]-'0';
		for(int i=n-2;i>=0;i--) {
			if(s[i][0]=='*') break;
			dp[i][0]=dp[i+1][0]+s[i][0]-'0';
		}
		for(int i=1;i<m;i++){
			for(int j=0;j<n;j++){
				if(dp[j][i-1]<0) continue;
				int t=dp[j][i-1];
				for(int k=j;k<n;k++){
					if(s[k][i]-'0'<0) k=n;
					else{
						t+=s[k][i]-'0';
						if(t>dp[k][i]) dp[k][i]=t;
					}
				}
			}
			for(int j=n-1;j>=0;j--){
				if(dp[j][i-1]<0) continue;
				int t=dp[j][i-1];
				for(int k=j;k>=0;k--){
					if(s[k][i]-'0'<0) k=-1;
					else{
						t+=s[k][i]-'0';
						if(t>dp[k][i]) dp[k][i]=t;
					}
				}
			}
		}
		printf("%d\n",dp[n-1][m-1]);
	}
}
