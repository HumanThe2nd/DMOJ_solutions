/*
DMOPC '19 Contest 7 P3 - Tree Pruning
Author: Dan Shan
Date: 2025-05-23
Case 1: a node between k and 2k -> return the single node
Case 2: delete all nodes over 2k, try every remaining tree stopping when weight > k
Since the remaining nodes are all less than k, it would be optimal to keep connecting nodes until minimum reached
Case 3: minimum can't be reached for any remaining subtree -> impossible
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    ll a[n+1],v[n+1];
    for(int i=1;i<=n;++i){
        cin >> a[i];
        if(a[i]>=k&&a[i]<=2*k) return !printf("1\n%d\n",i); // single valid node
        v[i]=(a[i]>2*k); // can't use these nodes
    }
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;++i){
        int ai,bi;
        cin >> ai >> bi;
        adj[ai].emplace_back(bi);
        adj[bi].emplace_back(ai);
    }
    for(int i=1;i<=n;++i){
        if(v[i]) continue;
        ll wi=0;
        queue<int> q,res;
        q.emplace(i); v[i]=1;
        while(!q.empty()){
            int ni=q.front(); q.pop();
            wi+=a[ni];
            res.emplace(ni);
            if(wi>=k) break;
            for(auto x: adj[ni]){
                if(v[x]) continue;
                v[x]=1; q.emplace(x);
            }
        }
        if(wi>=k){
            cout << res.size() << "\n";
            cout << res.front(); res.pop();
            while(res.size()) {
                cout << " " << res.front();
                res.pop();
            }
            cout << "\n";
            return 0;
        }
        
    }
    cout << "-1\n";
}
