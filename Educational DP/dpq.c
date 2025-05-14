/*
Educational DP Contest AtCoder Q - Flowers
Author: HumanThe2nd
Date: 2025-04-23
Topics: Dynamic Programming + Data Structures
Approach: DP array + Fenwick/Binary-Indexed Tree
Find maximize height at each index using a DP array with a BIT
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
typedef long long ll;
ll tree[200001],dp[200001],n;
ll q(int ai){
    ll res=0;
    while(ai){
        if(tree[ai]>res) res=tree[ai];
        ai-=ai&-ai;
    }
    return res;
}
void u(int ai, ll hi){
    for(;ai<=n;ai+=ai&-ai){
        if(hi>tree[ai]) tree[ai]=hi;
    }
}
int main() {
    scanf("%d",&n);
    int h[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
        int hi=h[i],ai;
        scanf("%d",&ai);
        dp[i]=q(hi-1)+ai;
        u(hi,dp[i]);
    }
    ll res=0;
    for(int i=0;i<=n;i++) if(dp[i]>res) res=dp[i];
    printf("%lld\n",res);
}
