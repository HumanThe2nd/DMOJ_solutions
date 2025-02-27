/*
COCI '21 Contest 3 #2 Cijanobakterije
Author: Dan Shan
Date: 2024-11-18
given a forest find the sum of the diameters of each tree
since connecting the 2 edges of the diameters is optimal for length
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int r,d;
vector<int> v; // visit each node only once
void dfs(int n, int p, int w){
    if(w>d){
        d=w; r=n;
    }
    v[n]=1;
    for(auto x: adj[n]){
        if(x!=p) dfs(x,n,w+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,c=0;
    cin >> n >> m;
    adj.resize(n+1);
    v.resize(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i=1;i<=n;i++){ // bfs each unvisited node
        if(v[i]) continue;
        r=1; d=0;
        dfs(i,0,1);
        dfs(r,0,1);
        c+=d;
    }
    cout << c << "\n";
}
