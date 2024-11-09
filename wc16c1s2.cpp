/*
WC '16 Contest 1 S2 - Alucard's Quest
Author: Dan Shan
Date: 2024-11-09
Given K mandatory destinations in a weighted graph
start from node 1 visit all relevant nodes K then return
simplified to just minimum weight to each item as weights only count once
solution: dfs tracking weights and if relevant node found, add the weights
*/
#include <bits/stdc++.h>
using namespace std;
class p{
    public:
    int f,s; // node, weight
};
int v[200001],r[200001]; // visited, relevant
vector<vector<p>> adj;
int dfs(int a){
    v[a]=1;
    int rel=r[a],c=0;
    for(p x: adj[a]){
        if(v[x.f]) continue;
        int ci=dfs(x.f);
        if(ci||r[x.f]){
            c+=ci+x.s; // add child and next weight
            rel=1;
        }
    }
    return rel?c:0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    adj.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b,m;
        cin >> a >> b >> m;
        adj[a].push_back({b,m});
        adj[b].push_back({a,m});
    }
    while(k--){
        int ki;
        cin >> ki;
        r[ki]=1;
    }
    cout << dfs(1) << "\n";
}
