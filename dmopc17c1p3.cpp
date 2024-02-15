/* DMOPC '17 Contest 1 P3 - Hitchhiking Fun
 * By: Dan Shan
 * Theory: danger adds 1e5 weight distance adds one
 * run dijkstra's and divide by 1e5 for danger and mod 1e5 for distance on ending node
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> pi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,MM=1e5;
    cin >> n >> m; // min length and danger
    ll dp[n+1]; dp[1]=0;
    for(ll i=2;i<=n;i++) dp[i]=1e12;
    vector<vector<pi>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    priority_queue<pi,vector<pi>,greater<>> pq;
    pq.emplace(0,1);
    while(!pq.empty()){
        ll vi=pq.top().first,ni=pq.top().second;
        pq.pop();
        if(vi!=dp[ni]) continue;
        for(auto edge: adj[ni]) {
            ll nf = edge.first,di=edge.second;
            if(dp[ni]+di*MM+1<dp[nf]){
                dp[nf]=dp[ni]+di*MM+1;
                pq.emplace(dp[nf],nf);
            }
        }
    }
    if(dp[n]==(ll)1e12)printf("-1\n");
    else printf("%lld %lld\n",dp[n]/MM,dp[n]%MM);
}
