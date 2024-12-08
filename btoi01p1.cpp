/*
Baltic OI '01 P1 - Postman
Author: Dan Shan
Date: 2024-12-08
DFS undirected graph removing edges when visiting instead of nodes
Cost is irrelevant, all villages must be visited
Note: some paths can occur multiple times or connect a node to itself
*/
#include <bits/stdc++.h>
using namespace std;
vector<multiset<int>> adj;
vector<int> res;
void dfs(int n) {
    while (!adj[n].empty()) {
        auto it = adj[n].begin();
        int x = *it;
        adj[n].erase(it);
        adj[x].erase(adj[x].find(n));
        dfs(x); // never use this path again
    }
    res.emplace_back(n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,c;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=0;i<n;i++) cin >> c;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs(1);
    int s=res.size();
    cout << s-1 << "\n";
    for(int i=0;i<s-1;i++) cout << res[i] << " ";
    cout << "1\n";
}
