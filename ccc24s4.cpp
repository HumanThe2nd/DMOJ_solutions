// CCC '24 S4 - Painting Roads
// By: Dan Shan
// template dfs
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int v[200002],arr[200001];
vector<vector<pi>> adj(200001);
void dfs(int a, int clr){
    v[a]=1;
    for(pi x: adj[a]){
        if(!v[x.first]){
            arr[x.second]=clr;
            dfs(x.first,clr==1?2:1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b,i);
        adj[b].emplace_back(a,i);
    }
    for(int i=0;i<n;i++){
        if(!v[i]) dfs(i,1);
    }

    for(int i=0;i<m;i++){
        if(arr[i]==0)printf("G");
        else if(arr[i]==1)printf("R");
        else printf("B");
    }
    printf("\n");
}
