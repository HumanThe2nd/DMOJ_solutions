/*
GFSSOC '15 Fall S4 - Mostly Talking
Author: Dan Shan
Date: 2025-05
Method 1
2 State Dijsktra's algroithm 
Store minimum distance using 0 special paths and with 1
Take minimum at the end
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<ll> d(n+1,2e12),d2(n+1,2e12);
    vector<vector<pair<ll,ll>>> adj(n+1),adj2(n+1);
    while(m--){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
    }
    cin >> m;
    while(m--){ // special paths
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj2[ai].push_back({bi,ci});
    }
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>> pq;
    pq.push({0,0,1}); // dist, path (0 or 1), node
    while(pq.size()){
        auto ti=pq.top(); pq.pop();
        ll di=get<0>(ti),pi=get<1>(ti),ni=get<2>(ti);
        if(!pi&&di>d[ni]) continue; // suboptimal
        if(pi&&di>d2[ni]) continue; 
        if(!pi){ // no special paths used yet
            for(auto x: adj[ni]){ // regular path
                ll df=di+x.second,nf=x.first;
                if(d[nf]>df) {
                    d[nf]=df;
                    pq.push({df,0,nf});
                }
            }
            for(auto x: adj2[ni]){ // use special path
                ll df=di+x.second,nf=x.first;
                if(d2[nf]>df) {
                    d2[nf]=df;
                    pq.push({df,1,nf});
                }
            }
        }
        else{ // already used special path
            for(auto x: adj[ni]){ // regular path
                ll df=di+x.second,nf=x.first;
                if(d2[nf]>df) {
                    d2[nf]=df;
                    pq.push({df,1,nf});
                }
            }
        }
    }
    ll res=min(d[n],d2[n]);
    if(res==2e12) cout << "-1\n";
    else cout << res << "\n";
}
/*
Method 2
Dijsktra's algroithm twice
Run Dijkstra's from start and end tracking min distance to each node
Find maximum gain by inserting each special edge in O(1) per edge
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,inf=2e16;
    cin >> n >> m;
    vector<ll> d(n+1,inf),d2(n+1,inf);
    d[1]=0; d2[n]=0;
    vector<vector<pair<ll,ll>>> adj(n+1),adj2(n+1);
    while(m--){
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi,ci});
        adj2[bi].push_back({ai,ci});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    pq.push({0,1});
    while(pq.size()){ // start to end
        auto pi=pq.top(); pq.pop();
        ll di=pi.first,ni=pi.second;
        if(di>d[ni]) continue; // suboptimal
        for(auto x: adj[ni]){
            ll df=di+x.second,nf=x.first;
            if(df<d[nf]){
                d[nf]=df;
                pq.push({df,nf});
            }
        }
    }
    pq.push({0,n});
    while(pq.size()){ // start to end
        auto pi=pq.top(); pq.pop();
        ll di=pi.first,ni=pi.second;
        if(di>d2[ni]) continue; // suboptimal
        for(auto x: adj2[ni]){
            ll df=di+x.second,nf=x.first;
            if(df<d2[nf]){
                d2[nf]=df;
                pq.push({df,nf});
            }
        }
    } cin >> m;
    ll res=d[n];
    while(m--){ // special paths
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        res=min(res,d[ai]+d2[bi]+ci);
    }
    if(res==inf) cout << "-1\n";
    else cout << res << "\n";
}
