// Railgun
// By: Dan Shan
#include<stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
int n,s,t;
scanf("%d %d %d",&n,&s,&t);
int dp[n+1];
dp[0]=0;
for(int i=1;i<=n;i++){
    scanf("%d",&dp[i]);
    dp[i]+=dp[i-1];
}
if(t*s>=n){
    printf("%d\n",dp[n]);
    return 0;
}
int m=0;
for(int i=0;i<=t;i++)
    m = MAX(m,dp[n]-dp[n-i*s]+dp[(t-i)*s]);
printf("%d\n",m);
}
