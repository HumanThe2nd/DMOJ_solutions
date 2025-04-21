/*
THICC '17 P6 - Tunnels
Author: HumanThe2nd
Date: 2025-04-21
Select nodes with connection degree of 'T'
Compute diameter, subtract the distance of the diameter furthest from the node from 2*total_weight
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,lim=0;
vector<vector<pair<ll,ll>>> adj;
vector<ll> ind,d,d2,d1; // indegree, dist
int dfs(int ni, int pi, ll di){ // node, parent, dist
    d[ni]=di;
    ll mx=di,res=ni;
    for(auto x: adj[ni]){
        if(x.first==pi) continue;
        ll nf=dfs(x.first,ni,di+x.second);
        if(d[nf]>mx){
            mx=d[nf];
            res=nf;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    adj.resize(n+1);
    ind.resize(n+1,0);
    d=ind; d1=d; d2=d;
    for(int i=1;i<n;i++){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
        adj[bi].push_back({ai,ci});
        ind[ai]++; ind[bi]++;
        lim+=ci; // total distance
    }
    ll s=dfs(1,-1,0);
    d1=d;
    ll e=dfs(s,-1,0);
    d2=d;
    dfs(e,-1,0);
    for(int i=1;i<=n;i++){
        if(ind[i]==t){
            ll mx=max(d[i],d2[i]);
            printf("%d %lld\n",i,2*lim-mx);
        }
    }
}
