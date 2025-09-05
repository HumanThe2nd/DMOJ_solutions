/*
Mice and Maze
Author: Dan Shan
Date: 2025-09-05

1. Build edges in reverse
2. Run Dijkstra from the exit cell
3. Count the number of mice reached with time equal to or less than T 

*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti;
    cin >> ti;
    while(ti--){
        int n, e, t, m, c=0;
        cin >> n >> e >> t >> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> d(n+1, 2e9);
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<m; ++i){
            int ai,bi,ci;
            cin >> ai >> bi >> ci;
            adj[bi].push_back({ai, ci});
        } d[e] = 0;
        pq.emplace(0, e);
        while(pq.size()){
            int di=pq.top().first, ai=pq.top().second;
            pq.pop();
            if(di > d[ai]) continue;
            for(auto x: adj[ai]){
                int df = di + x.second, af = x.first;
                if(df < d[af]){
                    pq.emplace(df, af);
                    d[af] = df;
                }
            }
        }
        for(int i=1; i<=n; ++i) c += d[i] <= t;
        cout << c << "\n";
    }
}
