// Educational DP Contest AtCoder P - Independent Set
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
const int m=1e9+7;
vector<vector<int>>adj;
vector<int> dp0,dp1,parent;
void dfs(int v){
    dp0[v]=1;
    dp1[v]=1;
    for (int u:adj[v]) {
        if(u==parent[v]) continue;
        parent[u]=v;
        dfs(u);
        dp0[v]=(long long)dp0[v]*(dp0[u]+dp1[u])%m;
        dp1[v]=(long long)dp1[v]*dp0[u]%m;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    adj.resize(n+1);
    dp0.resize(n+1);
    dp1.resize(n+1);
    parent.resize(n+1);
    for (int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1);
    int res=(dp0[1]+dp1[1])%m;
    printf("%d\n",res);
    return 0;
}
