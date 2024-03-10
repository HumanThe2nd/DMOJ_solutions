// Bank Notes
// By: Dan Shan
#include <stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int main() {
    int n,k;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    scanf("%d",&k);
    int dp[k+1];
    for(int i=1;i<=k;++i) dp[i]=2e9;
    dp[0]=0;
    for(int i=0;i<n;++i) {
        for(int j=k;j>=a[i];--j){
            for(int l=1;l<=min(j/a[i],b[i]);++l){
            if(dp[j-l*a[i]]!=2e9) {
                dp[j]=min(dp[j],dp[j-l*a[i]]+l);
            }
            }
        }
    }
    printf("%d\n",dp[k]);
}
