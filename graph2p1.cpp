/*
Graph Contest 2 P1 - Connected Components
Author: Dan Shan
Date: 2025-05-19
Group every unvisited node with nodes it reaches with BFS
Sort each group before outputting
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            int ai;
            cin >> ai;
            if(!ai) continue;
            adj[i].emplace_back(j);
            adj[j].emplace_back(i);
        }
    for(int i=1;i<=n;++i){
        if(v[i]) continue;
        vector<int> res={i};
        v[i]=1;
        queue<int> q;
        q.emplace(i);
        while(q.size()){
            int xi=q.front();
            q.pop();
            for(auto x: adj[xi]){
                if(v[x]) continue;
                v[x]=1; q.emplace(x);
                res.emplace_back(x);
            }
        }
        sort(res.begin(),res.end());
        cout << res[0];
        for(int j=1;j<res.size();++j) cout << " " << res[j];
        cout << "\n";
    }
}
