/*
IOI '13 P1 - Dreaming
Author: HumanThe2nd
Date: 2025-04-19
1. Find the 2 longest paths per subtree from its center
2. Result is the max of: any of these 2 paths from different trees
Note: add L for each path from trees without max radius
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long ll;
int travelTime(int n, int m, int l, int a[], int b[], int t[]){
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<pair<ll,ll>> r;
    for(int i=0;i<m;i++){
        adj[a[i]].push_back({b[i],t[i]});
        adj[b[i]].push_back({a[i],t[i]});
    }
    vector<ll> v(n+1,0),d(n+1,0); // store diameters for Q = 1, radius for Q = 2
    for(int i=0;i<n;i++){
        if(v[i]) continue; // visited
        stack<pair<ll,ll>> stk;
        ll s=i,e=i,dia=0,ri=2e15; // start of diameter, end of diameter, max dist/diameter, radius
        stk.push({i,0}); // find distance to each node
        v[i]=1;
        while(stk.size()){
            ll ni=stk.top().first,di=stk.top().second;
            stk.pop();
            for(auto x: adj[ni]){
                if(v[x.first]) continue;
                v[x.first]=1;
                ll df=di+x.second;
                if(df>dia){ // find one end of diameter
                    dia=df; s=x.first;
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
                if(df>=dia){ // find second endpoint
                    dia=df; e=x.first;
                }
                d[x.first]=df; // store distance start node
                stk.push({x.first,df});
            }
        }
        stk.push({e,0});
        v[e]=3;
        while(stk.size()){
            ll ni=stk.top().first,di=stk.top().second;
            stk.pop();
            ri=min(ri,max(di,d[ni])); // potential radius: max of the dist between start and end
            for(auto x: adj[ni]){
                if(v[x.first]>2) continue;
                v[x.first]=3;
                ll df=di+x.second;
                stk.push({x.first,df});
            }
        }
        r.push_back({ri,dia-ri}); 
    }
    ll res=0;
    sort(r.rbegin(),r.rend());
    for(auto x:r){
        res=max(res,x.first+x.second);
    }
    if(r.size()>1) res=max(res,r[0].first+r[1].first+l);
    if(r.size()>2) res=max(res,r[1].first+r[2].first+2*l);
    return res;
}
