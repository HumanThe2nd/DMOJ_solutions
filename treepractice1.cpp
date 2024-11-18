/*
Tree Tasks
Author: Dan Shan
Date: 2024-11-17
dfs furthest node from a random node.
dfs again from that node to the furthest node to find diameter
dfs again from second end of the diameter
for last 2 dfs calls store distance to each node
the radius will be the minimum of the maximum between the 2 values
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
int r=1,m=0;
vector<int> d;
void dfs(int n, int p, int w){
    if(w>m){
        m=w; r=n;
    }
    d[n]=w;
    for(auto x: adj[n]){
        if(x.first!=p) dfs(x.first,n,w+x.second);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n+1);
    d.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dfs(1,0,0);
    dfs(r,0,0);
    int r2=r;
    vector<int> d1=d;
    dfs(r2,0,0);
    vector<int> d2=d;
    int rad=2e9;
    for(int i=1;i<=n;i++){
        rad = min(rad,max(d1[i],d2[i]));
    }
    cout << m << "\n" << rad << "\n";
}
