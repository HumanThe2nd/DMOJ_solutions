/*
DMOPC '17 Contest 1 P4 - Quests
Author: HumanThe2nd
Date: 2025-04-22
Approach: Unbounded + 1/0 knapsack
1. For each npc, try going to it (1/0 addition)
2. store a seperate dp array per npc for maximum values that visit them
3. Try every number of quests at the npc after reaching (unbounded)
Time Complexity: O(N*H)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
typedef long long ll;
const ll inf=1e18;
int main() {
    ll n,h,res=0;
    scanf("%lld %lld",&n,&h);
    ll dp[h+1]; dp[0]=0;
    for(int i=1;i<=h;i++) dp[i]=-inf;
    for(int i=1;i<=n;i++){
        ll gi,hi,qi,ti,dpi[h+1]; // reach: gold, time; quest: gold, time; dp assuming visited
        for(ll j=0;j<=h;j++) dpi[j]=-inf;
        scanf("%lld %lld %lld %lld",&gi,&hi,&qi,&ti);
        for(int j=h;j>=hi;j--){ // 1-0 Knpsack with visiting npcs
            ll ai=dp[j-hi]+gi;
            if(ai>dp[j]) dp[j]=ai;
            if(ai>dpi[j]) dpi[j]=ai;
        }
        for(int j=ti;j<=h;j++){ // Unbounded Knapsack on cells that visit the npc
            ll ai=dpi[j-ti]+qi;
            if(ai>dpi[j]) dpi[j]=ai;
            if(dpi[j]>dp[j]) dp[j]=dpi[j]; // Merge the 2nd dp with the main
        }
    }
    for(ll i=0;i<=h;i++) if(dp[i]>res) res=dp[i];
    printf("%lld\n",res);
}
