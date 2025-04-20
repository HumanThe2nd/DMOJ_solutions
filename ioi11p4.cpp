/*
IOI '11 P4 - Crocodile's Underground City
Author: HumanThe2nd
Date: 2025-04-20
Modified Dijkstra's algorithm
Only expand a node (or exit) if it's been visited before already
This code start from the exits and move backwards
Note: don't forget the exits are also nodes that start visited once (with distance = 0)
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long ll;
int travel_plan(int n, int m, int r[][2], int c[], int k, int e[]){
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i=0;i<m;i++){
        adj[r[i][1]].push_back({r[i][0],c[i]});
        adj[r[i][0]].push_back({r[i][1],c[i]});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    vector<ll> v(n,0);
    for(int i=0;i<k;i++){
        pq.push({0,e[i]});
        v[e[i]]=1;
    }
    while(pq.size()){
        ll di=pq.top().first,ni=pq.top().second;
        pq.pop();
        if(!v[ni]){ // may be blocked
            v[ni]=1;
            continue;
        }
        if(v[ni]>1) continue; // sub-optimal
        if(!ni){ // target found
            return di;
        }
        v[ni]++;
        for(auto x: adj[ni]){
            ll nf=x.first,df=x.second+di;
            if(v[nf]>1) continue; // sub-optimal
            pq.push({df,nf});
        }
    }
}
