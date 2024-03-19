// Educational DP Contest AtCoder G - Longest Path
// By: Dan Shan
// Theory: Find ending vertexes
// DFS from each ending nodes storing distance to each node  
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
int dfs(int v) {
    if (dp[v]!=-1) return dp[v];
    int mx=0;
    for(int i=0;i<adj[v].size(); i++) {
        mx=max(mx,dfs(adj[v][i])+1);
    }
    dp[v]=mx;
    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    dp.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,dfs(i));
    }
    printf("%d\n",mx);
}
