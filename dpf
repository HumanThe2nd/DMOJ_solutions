// Educational DP Contest AtCoder F - LCS
// By: Dan Shan
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
    char a[3001],a2[3001];
    scanf("%s %s",a,a2);
    int n=0,m=0;
    for(int i=0;i<=3000;i++) {
    	if(a[i]=='\0'){
    		n=i; break;
    	}
    }
    for(int i=0;i<=3000;i++) {
        	if(a2[i]=='\0'){
        		m=i; break;
        	}
        }
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++){
    	for(int j=0;j<=n;j++) dp[j][i]=0;
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(a[i-1]==a2[j-1])dp[i][j]=dp[i-1][j-1]+1;
    		else dp[i][j]= MAX(dp[i-1][j],dp[i][j-1]);
    	}
    }
    int i=n,j=m,idx=dp[n][m];
    char lcs[idx+1]; lcs[idx]='\0';
    while(i>0&&j>0){
    	if(a[i-1]==a2[j-1]){
    		lcs[idx-1]=a[i-1];
    		i--;j--; idx--;
    	}
    	else if(dp[i-1][j]>dp[i][j-1])i--;
    	else j--;
    }
    printf("%s\n",lcs);
}
