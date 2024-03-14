// Educational DP Contest AtCoder H - Grid 1
// By: Dan Shan
#include <stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    long long dp[n][m];
    for(int i=0;i<n;i++){
            char s[m+1];
            scanf("%s",s);
            for(int j=0;j<m;j++){ 
            if(s[j]-'.'==0)a[i][j]=0;
            else a[i][j]=1;
            dp[i][j]=0;
            }
    } dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
        if(a[i][j]) continue;
        dp[i][j]%=1000000007;
        if(j<m-1)dp[i][j+1]+=dp[i][j];
        if(i<n-1)dp[i+1][j]+=dp[i][j];
        }
    }
    printf("%lld\n",dp[n-1][m-1]%(1000000007));
}
