// MEC '16 P3 - Getting Good at Programming
// By: Dan Shan
// Conflicting items knapsack
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    int dp[t+1],w[n][100],v[n][100],c[n];
    for(int i=0;i<=t;i++)dp[i]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        for(int j=0;j<c[i];j++) {
            scanf("%d %d",&w[i][j],&v[i][j]);
            if(j){
                w[i][j]+=w[i][j-1];
                v[i][j]+=v[i][j-1];
            }
        }

    }
    for(int i=0;i<n;i++){
        for(int j=t;j>=0;j--){
            for(int k=c[i]-1;k>=0;k--){
                if(w[i][k]>j) continue;
                dp[j]=max(dp[j],dp[j-w[i][k]]+v[i][k]);
            }
        }
    }
    printf("%d\n",dp[t]);
}
