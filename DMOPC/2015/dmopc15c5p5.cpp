/*
DMOPC '15 Contest 5 P5 - World Line Convergence
Author: Dan Shan
Date: 2025-07-07
1. Binary Indexed Tree: Prefix sum of divergence
2. Store order of visits for tree indexes
3. DFS from root down to leaves, updating and querying in the order Okarin visits them
TC: O(N*log(N))
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
vector<int> adj[200001]; // world line
ll bit[200001],ind[200001],res[200001],m=1e9+7,n,r=0;
ll q(int xi){ // BIT query
    ll c=0;
    for(int i=xi;i>0;i-=i&-i) c+=bit[i];
    return c;
}
void dfs(int xi){
    ll ai=q(ind[xi]); // original value
    for(auto x: adj[xi]) dfs(x); 
    res[xi]=(q(ind[xi])-ai+m+1)%m; // new value
    for(int i=ind[xi];i<=n;i+=i&-i) bit[i]+=res[xi]; // update BIT
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;++i){
        int pi;
        cin >> pi; --pi;
        if(pi<0) r=i;
        else adj[pi].emplace_back(i);
    }
    for(int i=1;i<=n;++i){ // 
        int ai;
        cin >> ai;
        ind[--ai]=i;
    }
    dfs(r);
    cout << res[0];
    for(int i=1;i<n;++i) cout << " " << res[i];
    cout << "\n";
}
