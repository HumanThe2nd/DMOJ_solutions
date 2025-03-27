/*
CCC '15 S4 - Convex Hull
Author: HumanThe2nd
Date: 2025-03-27
Multi-dimension Dijsktra's
for each node, store minimum time for each valid and possible h values
take optimal time at final node in the valid range of h values
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,n,m,inf=2e9;
    cin >> k >> n >> m;
    vector<vector<tuple<int,int,int>>> adj(n);
    for(int i=0;i<m;i++){ 
        int ai,bi,ti,hi;
        cin >> ai >> bi >> ti >> hi;
        --ai; --bi;
        adj[ai].push_back({bi,ti,hi});
        adj[bi].push_back({ai,ti,hi});
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    vector<vector<int>> d(n,vector<int>(k,inf));
    int s,e;
    cin >> s >> e;
    --s; --e; // 0-index
    pq.push({0,0,s});
    d[s][0]=0;
    while(pq.size()){
        int di=get<0>(pq.top()),hi=get<1>(pq.top()),ni=get<2>(pq.top());
        pq.pop();
        if(di>d[ni][hi]) continue; // suboptimal
        for(auto x: adj[ni]){
            int nf=get<0>(x),df=di+get<1>(x),hf=hi+get<2>(x);
            if(hf>=k||df>d[nf][hf]) continue; // invalid or suboptimal
            d[nf][hf]=df;
            pq.push({df,hf,nf});
        }
    }
    int mn=inf;
    for(int i=0;i<k;i++){
        if(d[e][i]<mn) mn=d[e][i];
    }
    if(mn==inf) cout << "-1\n";
    else cout << mn << "\n";
}
