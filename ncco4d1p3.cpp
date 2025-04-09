/*
Mock CCO '18 Contest 4 Problem 3 - Counterattack
Author: HumanThe2nd
Date: 2025-04-09
2D Dijkstra's algorithm storing 1st and 2nd best paths to each node
Note: don't forget to replace 2nd max with 1st, when updating the 1st
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    while(m--){
        int ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
        adj[bi].push_back({ai,ci});
    }
    vector<ll> d(n+1,2e9),d2(n+1,2e9);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    pq.push({0,1});
    while(pq.size()){
        ll di=pq.top().first,ni=pq.top().second;
        pq.pop();
        if(di>d[ni]&&di>d2[ni]) continue; // not optimal for either path
        for(auto x: adj[ni]){
            ll nf=x.first,df=di+x.second;
            if(df<d[nf]) {
                d2[nf]=d[nf];
                d[nf]=df;
            }
            else if(df<d2[nf]&&df>d[nf]) d2[nf]=df;
            else continue; // useless edge
            pq.push({df,nf});
        }
    }
    cout << d2[n] << "\n";
}
