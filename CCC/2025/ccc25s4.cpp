/*
CCC '25 S4 - Floor is Lava
Author: HumanThe2nd
Date: 2025-03-28
Dijsktra's on tunnels
Search cheapest tunnel until end node reached
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> t(m+1),d(m+1,2e18),v(m+1,0); // tunnels, distances
    for(int i=0;i<m;i++){
        ll ai,bi;
        cin >> ai >> bi >> t[i];
        adj[ai].push_back({bi,i});
        adj[bi].push_back({ai,i});
    }
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>> pq;
    pq.push({0,1,m}); // cost, node, tunnel
    while(pq.size()){
        ll di=get<0>(pq.top()),ni=get<1>(pq.top()),ti=get<2>(pq.top());
        pq.pop();
        if(ni==n){
            cout << di << "\n";
            return 0;
        }
        if(v[ti]) continue;
        for(auto x: adj[ni]){
            if(v[x.second]) continue;
            ll cf=di+abs(t[ti]-t[x.second]);
            if(cf<d[x.second]){
                d[x.second]=cf;
                pq.push({cf,x.first,x.second});
            }
        }
    }
}
