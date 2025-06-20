// DMOPC '18 Contest 2 P3 - Thanksgiving Feast
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 1e5+2;
int des[MM],dis[MM],vc[MM];
vector<vector<int>> adj(MM);
void bfs(int a){
    queue<int> q,qd;
    int v[MM];
    for(int &i:v) i=0;
    v[a]=1;
    q.emplace(a); qd.emplace(0);
    while(!q.empty()){
        int node = q.front(),d=qd.front();
        q.pop(); qd.pop();
        if(des[node]) {
            dis[node]+=d;
            vc[node]++;
        }
        for(auto x: adj[node]){
            if(!v[x]){
                v[x]=1;
                q.emplace(x); qd.emplace(d+1);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k,a,b,min=2e9;
    cin >> n >> m >> k >> a >> b;
    for(int i=0;i<k;i++){
        int l;
        cin >> l;
        des[l]=1;
    }
    for(int i=0;i<m;i++){
        int s,l;
        cin >> s >> l;
        adj[s].push_back(l);
        adj[l].push_back(s);
    }
    bfs(a); bfs(b);
    for(int i=0;i<n;i++)
        if(dis[i]<min&&des[i]&&vc[i]>1)
            min = dis[i];
    cout << min << "\n";
}
