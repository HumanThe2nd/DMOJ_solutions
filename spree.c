// Coding Spree
// By: Dan Shan
// bounded knapsack
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))

int main() {
    int c,m;
    scanf("%d %d",&c,&m);
    int v[c],w[c],dp[m+1];
    for(int i=0;i<c;i++) {
        scanf("%d %d",&v[i],&w[i]);
    }
    for(int i=0;i<=m;i++) dp[i]=0;
    for(int i=1;i<=c;i++){
        for(int j=m;j>=0;j--){
            if(w[i-1]>j) continue;
            dp[j]=max(dp[j],dp[j-w[i-1]]+v[i-1]);
        }
    }
    printf("%d\n",dp[m]);
}
