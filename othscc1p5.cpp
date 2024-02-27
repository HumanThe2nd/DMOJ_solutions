// OTHS Coding Competition 1 (Mock CCC) J5 - Scavenger Hunt
// By: Dan Shan
/*
Theory: 2d Dijkstra's
Push initial node with time to make first item as weight priority queue,
Find each first item, push in weights and new nodes repeat with new initial nodes and new starting weights
Note: we must optimize by removing same starting nodes with different weights by taking the minimum weight
in order to pass the final subtask.
*/
#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long,long long>;
int main() {
    std::istream::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m,k;
    cin >> n >> m >> k;
    long long t[k+1],l[k+1],b[n+1][k+1];
    memset(b,0,sizeof(b));
    for(long long i=1;i<=k;i++) cin >> t[i];
    for(long long i=1;i<=k;i++) cin >> l[i];
    for(long long i=1;i<=k;i++) {
        for (long long j = 0; j < l[i]; j++) {
            long long a;
            cin >> a;
            b[a][i] = 1;
        }
    }
    vector<vector<pi>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long ai,bi,ci;
        cin >> ai >> bi >> ci;
        adj[ai].emplace_back(bi,ci);
        adj[bi].emplace_back(ai,ci);
    }
    priority_queue<pi,vector<pi>,greater<>> nxt; // next layer
    nxt.emplace(0,1);
    for(long long i=1;i<=k;i++) {
        priority_queue<pi,vector<pi>,greater<>> pq,temp; // current layer
        long long d[n+1];
        for(int j=0;j<=n;j++)d[j]=2e18;
        while(!nxt.empty()) {
            pq.emplace(nxt.top());
            if(nxt.top().first<d[nxt.top().second]) {
                d[nxt.top().second] = nxt.top().first;
                temp.emplace(nxt.top());
            }
            nxt.pop();
        }
        while(!temp.empty()){ // create item
            long long ti = temp.top().first,ni=temp.top().second;
            ti+=t[i];
            nxt.emplace(ti,ni);
            temp.pop();
        }
        while(!pq.empty()){ // find next item
            long long ti = pq.top().first,ni=pq.top().second;
            pq.pop();
            if(b[ni][i]) nxt.emplace(ti,ni); // item found
            if(d[ni]!=ti)continue;
            for(pi edge: adj[ni]){
                long long nf=edge.first,w=edge.second;
                if(d[ni]+w<d[nf]) {
                    d[nf]=d[ni]+w;
                    pq.emplace(d[nf],nf);
                }
            }
        }
    }
    printf("%lld\n",nxt.top().first);
}
