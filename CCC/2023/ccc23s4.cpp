/*
CCC '23 S4 - Minimum Cost Roads
Author: Dan Shan
Date: 2025-05-28
Try pruning every edge by descending length (tiebreak by cost)
Dijkstra's to determine "new" distance and compare with length of edge
if distance doesn't change the edge can stay pruned and the cost is saved
else, add the edge back
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,res=0;
    cin >> n >> m;
    vector<vector<tuple<ll,ll,ll>>> adj(n+1);
    vector<tuple<int,int,int,int>> a(m);
    for(int i=0;i<m;++i) {
        ll ai,bi,li,ci;
        cin >> ai >> bi >> li >> ci;
        a[i]={li,ci,ai,bi};
        adj[ai].emplace_back(bi,li,ci);
        adj[bi].emplace_back(ai,li,ci);
        res+=ci;
    }
    sort(a.begin(),a.end(),greater<>()); // decreasing length
    for(int i=0;i<m;++i){
        ll li=get<0>(a[i]),ci=get<1>(a[i]),ai=get<2>(a[i]),bi=get<3>(a[i]);
        priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<>> pq;
        vector<ll> d(n+1,1e18);
        adj[ai].erase(remove(adj[ai].begin(),adj[ai].end(),make_tuple((ll)bi,(ll)li,(ll)ci)),adj[ai].end());
        adj[bi].erase(remove(adj[bi].begin(),adj[bi].end(),make_tuple((ll)ai,(ll)li,(ll)ci)),adj[bi].end());
        pq.emplace(0,ai); // find initial distance
        d[ai]=0;
        while(pq.size()){
            ll di=pq.top().first,ni=pq.top().second;
            pq.pop();
            if(di>d[ni]) continue; // sub-optimal
            for(auto[nf,lf,cf]: adj[ni]){
                if(di+lf>=d[nf]) continue;
                d[nf]=di+lf;
                pq.emplace(d[nf],nf); 
            }
        }
        if(d[bi]<=li){ // prune edge
            res-=ci; continue;
        }
        adj[ai].emplace_back(bi,li,ci);
        adj[bi].emplace_back(ai,li,ci);
    }
    cout << res << "\n";
}
