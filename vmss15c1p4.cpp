// VMSS '15 #4 - Frank and Roads
// By: Dan Shan
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,m,g,c=0;
    cin >> t >> n >> m >> g;
    vector<vector<pi>> adj(n+1);
    priority_queue<pi,vector<pi>,greater<>> q;
    q.emplace(0,0);
    int bs[n+1],d[n+1];
    for(int i=0;i<=n;i++){
        bs[i]=0; d[i]=1e9;
    } d[0]=0;
    for(int i=0;i<g;i++){
        int in;
        cin >> in;
        bs[in]=1;
    }
    for(int i=0;i<m;i++){
        int a,b,l;
        cin >> a >> b >> l;
        adj[a].emplace_back(b,l);
    }
    while(!q.empty()){
        int v = q.top().second,dv = q.top().first;
        q.pop();
        if(dv!=d[v]) continue;
        for(auto edge: adj[v]){
            int to = edge.first, len = edge.second;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                q.emplace(d[to],to);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(bs[i]&&d[i]<t) c++;
    printf("%d\n",c);
}
