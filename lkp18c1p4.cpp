/*
LKP '18 Contest 1 P4 - Fun in Föràg
Author: HumanThe2nd
Date: 2025-04-11
Binary search + Dijkstra's
Build graph with the index of each edge,
binary search different index limits and run dijstra's with nodes up to the limit
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    vector<vector<tuple<ll,ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({i,bi,ci}); // index, node, weight
        adj[bi].push_back({i,ai,ci});
    }
    ll s,e,t;
    cin >> s >> e >> t;
    ll l=1,r=m,res=-1;
    while(l<=r){ // Binary search + Dijkstra's
        ll mid=(l+r)>>1; 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
        vector<ll> d(n+1,2e18); d[s]=0;
        pq.push({0,s});
        while(pq.size()){
            ll ni=pq.top().second,di=pq.top().first;
            pq.pop();
            if(di>d[ni]) continue;
            for(auto x: adj[ni]){
                ll ind=get<0>(x),nf=get<1>(x),df=get<2>(x)+di;
                if(ind>=mid) continue; // pass doesn't cover
                if(df<d[nf]){
                    d[nf]=df;
                    pq.push({df,nf});
                }
            }
        }
        if(d[e]<=t) r=mid-1,res=mid;
        else l=mid+1;
    }
    cout << res << "\n";
}
