//============================================================================
// Name        : Graph Contest 2 P2 - Directed Acyclic Graph
// Author      : Dan Shan
//============================================================================
// Goal: check if a directed graph contains a cyclem, efficient memory and time
// Approach: for each node DFS if a visited node reached no false otherwise yes
// DFS: directed graph therefore must only report cycle found if visited node is
//      on a path that reaches itself represented by 1s
#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    vector<vector<int>> adj;
    vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = visited
    bool DFS(int node);
};

bool graph::DFS(int node){
    if(visited[node] == 2) return 1; // If the node is already completely processed, return true
    if(visited[node] == 1) return 0; // If the node is currently being visited cycle found

    visited[node] = 1; // Mark the node as visiting

    for(auto x:adj[node]) {
        if(!DFS(x)) return false;
    }

    visited[node] = 2; // Mark the node as completely processed
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    graph g;
    g.adj.resize(n+1);
    g.visited.resize(n+1, 0);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int node;
            scanf("%d",&node);
            if(node){
                g.adj[i].push_back(j);
            }
        }
    }
    
    bool acyclic = true;
    
    for(int i=1; i<=n; i++){ 
        acyclic = g.DFS(i);
        if(!acyclic) break;
        fill(g.visited.begin(), g.visited.end(), 0); // Reset visited array
    }
    
    if(acyclic) printf("YES");
    else printf("NO");
}
