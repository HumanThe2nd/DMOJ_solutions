/*
IOI '11 P2 - Race (Standard I/O)
Author: Dan Shan
Date: 2025-06-07
1. dynamic programming to store min length for each weight
2. centroid decomposition to compute min per path
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,res=2e9,cent;
vector<vector<pair<int, int>>> adj;
vector<int> b,sz; // min length, blocked nodes, visted
vector<unordered_map<int,int>> d; // 
void dfs(int ni,int pi){ // compute all subtree sizes
    sz[ni]=1;
    for(auto x: adj[ni]){
       int nf=x.first;
       if(nf==pi||b[nf]) continue;
       dfs(nf,ni);
       sz[ni]+=sz[nf];
   }
}
int fc(int ni, int pi,int t){ // find centroid
    for(auto x: adj[ni]){
        int nf=x.first;
        if(!b[nf]&&nf!=pi&&sz[nf]*2>t) return fc(nf,ni,t);
    }
    return ni;
}
void dfs2(int ni, int pi, int li, int wi){ // try to find optimal path
    if(k>=wi&&d[cent].find(k-wi)!=d[cent].end()) res=min(res,li+d[cent][k-wi]);
    for(auto x: adj[ni]){
        int nf=x.first;
        if(b[nf]||nf==pi) continue;
        dfs2(nf,ni,li+1,wi+x.second);
    }
}
void dfs3(int ni,int pi, int li, int wi){ // update possible paths
    if(d[cent].find(wi)==d[cent].end()) d[cent][wi]=li;
    else d[cent][wi]=min(d[cent][wi],li);
    for(auto x: adj[ni]){
        int nf=x.first;
        if(nf==pi||b[nf]) continue;
        dfs3(nf,ni,li+1,wi+x.second);
    }
}
int solve(int ni){
    dfs(ni,-1);
    int pi=fc(ni,-1,sz[ni]); cent=pi;
    b[pi]=1; d[cent][0]=0;
    for(auto x: adj[pi]){
        int nf=x.first,di=x.second;
        if(b[nf]) continue;
        dfs2(nf,pi,1,di);
        dfs3(nf,pi,1,di);
    }
    for(auto xi: adj[pi]){
        if(!b[xi.first]) solve(xi.first);
    }
    return pi;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    adj.resize(n+1);
    d.resize(n+1);
    sz.resize(n+1);
    b.resize(n+1);
    for(int i=1;i<n;++i){
        int ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].emplace_back(bi,ci);
        adj[bi].emplace_back(ai,ci);
    }
    solve(0);
    if(res<2e9) cout << res << "\n";
    else cout << "-1\n";
}
