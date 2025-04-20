/*
IOI '11 P4 - Crocodile's Underground City (Standard I/O)
Author: HumanThe2nd
Date: 2025-04-20
Modified Dijkstra's algorithm
Only expand a node (or exit) if it's been visited before already
This code start from the exits and move backwards
Note: don't forget the exits are also nodes that start visited once (with distance = 0)
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll>>> adj(n);
    while(m--){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
        adj[bi].push_back({ai,ci});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    vector<ll> v(n,0);
    for(int i=0;i<k;i++){
        ll ai;
        cin >> ai;
        pq.push({0,ai});
        v[ai]=1;
    }
    while(pq.size()){
        ll di=pq.top().first,ni=pq.top().second;
        pq.pop();
        if(!v[ni]){ // may be blocked
            v[ni]=1;
            continue;
        }
        if(!ni){ // target found
            cout << di << "\n";
            return 0;
        }
        if(v[ni]>1) continue; // sub-optimal
        v[ni]++;
        for(auto x: adj[ni]){
            ll nf=x.first,df=x.second+di;
            if(v[nf]>1) continue; // sub-optimal
            pq.push({df,nf});
        }
    }
}
