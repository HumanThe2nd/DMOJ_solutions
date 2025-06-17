/*
Meta
Author: Dan Shan
Date: 2025-06-17

Goal:
1. Find the tree's diameter and 2 possible endpoints.
2. Count nodes that visit all valid endpoints starting from the 2 nodes found previously 

Note: This version prioritizes clarity. A slightly faster submission exists using more aggressive optimizations.
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
vector<vector<int>> adj;
vector<int> d,g;
int r1,dia=-1,r2,mx=0;
void fn(int ni, int pi, int di){ // find furthest node
    if(di>dia) dia=di,r1=ni;
    for(auto x: adj[ni]){
        if(x!=pi) fn(x,ni,di+1);
    }
}
int dfs(int ni, int pi, int di){ // # alternative paths per node & max
    d[ni]+=di==dia;
    for(auto x: adj[ni]){
        if(x!=pi) d[ni]+=dfs(x,ni,di+1);
    }
    mx=max(mx,d[ni]);
    return d[ni];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,c=0;
    cin >> n;
    adj.resize(n+1);
    d.resize(n+1,0); g=d;
    for(int i=1;i<n;++i){
        int ai,bi;
        cin >> ai >> bi;
        adj[ai].emplace_back(bi);
        adj[bi].emplace_back(ai);
    }
    fn(1,0,0); r2=r1; // endpoint 2
    dia=-1;
    fn(r1,0,0); // endpoint 1
    dfs(r2,0,0); // p1 paths
    for(int i=1;i<=n;++i) if(d[i]==mx) ++g[i];
    fill(d.begin(),d.end(),0); mx=0;
    dfs(r1,0,0); // p2 paths
    for(int i=1;i<=n;++i) if(d[i]==mx&&g[i]) ++c;
    cout << c << "\n";
}
