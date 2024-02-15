/* 
 * Maximum Sum
 * By: Dan Shan
 * Theory: optimal choice is to move up by either 2 or 3
 * Approach: push dp trying adding above 2 and above 3
 */
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
    int n;
    scanf("%d",&n);
    int a[n+1],dp[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++) dp[i]=0;
    dp[1]=a[1];
    if(n>1)dp[2]=MAX(a[1],a[2]);
    for(int i=3;i<=n;i++) {
        dp[i]=MAX(dp[i-1],dp[i-2]+a[i]);
    }
    printf("%d\n",dp[n]);
}
