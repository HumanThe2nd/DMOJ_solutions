/*
TLE '16 Contest 4 P4 - Christmas Tree Building
Author: HumanThe2nd
Date: 2025-04-18
Q = 1 -> Max height: sum of diameters
Q = 2 -> Min height: max radius among subtrees, if occurs more than once, add 1 to height

Diameter -> 1. DFS furthest node from any node for one end
            2. DFS from that end to find the other
Radius ->   1. Find diameter and the 2 endpoints
            2. Find the node such that the max distance to either endpoints is minimal
                the maximum distance to the endpoint from that node will be the radius
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,q,rad=0,f=0; // rad: max radius, f: duplicate of max radius?
    cin >> n >> m >> q;
    vector<vector<pair<ll,ll>>> adj(n+1);
    while(m--){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
        adj[bi].push_back({ai,ci});
    }
    vector<ll> v(n+1,0),d(n+1,0),res; // store diameters for Q = 1, radius for Q = 2
    for(int i=1;i<=n;i++){
        if(v[i]) continue; // visited
        stack<pair<ll,ll>> stk;
        ll s=i,e=i,mx=0; // start of diameter, end of diameter, max length
        stk.push({i,0}); // find distance to each node
        v[i]=1;
        while(stk.size()){
            ll ni=stk.top().first,di=stk.top().second;
            stk.pop();
            for(auto x: adj[ni]){
                if(v[x.first]) continue;
                v[x.first]=1;
                ll df=di+x.second;
                if(df>mx){ // find one end of diameter
                    mx=df; s=x.first;
                }
                stk.push({x.first,df});
            }
        }
        stk.push({s,0});
        v[s]=2;
        while(stk.size()){
            ll ni=stk.top().first,di=stk.top().second;
            stk.pop();
            for(auto x: adj[ni]){
                if(v[x.first]>1) continue;
                v[x.first]=2;
                ll df=di+x.second;
                if(df>=mx){ // find second endpoint
                    mx=df; e=x.first;
                }
                d[x.first]=df; // store distance start node
                stk.push({x.first,df});
            }
        }
        if(q==1){
            res.emplace_back(mx); // diameter
            continue;
        }
        stk.push({e,0});
        v[e]=3;
        while(stk.size()){
            ll ni=stk.top().first,di=stk.top().second;
            stk.pop();
            mx=min(mx,max(di,d[ni])); // potential radius: max of the dist between start and end
            for(auto x: adj[ni]){
                if(v[x.first]>2) continue;
                v[x.first]=3;
                ll df=di+x.second;
                stk.push({x.first,df});
            }
        }
        if(mx>rad) rad=mx,f=0;
        else if(mx==rad) f=1;
    }
    if(q==1){
        ll c=res.size()-1; // connection cost: 1
        for(auto x: res) c+=x; // sum of diameters
        cout << c << "\n";
    }
    if(q==2){
        if(f) rad++;
        cout << rad << "\n";
    }
}
