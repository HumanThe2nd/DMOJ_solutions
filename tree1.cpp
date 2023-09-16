// Is it a Tree?
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Graph{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void DFS(int v);
};
void Graph::DFS(int v)
{   
    visited[v] = 1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]) DFS(*i);
          }
}
int main(){
  Graph g;
  int edges=0;
  vector<vector<int>> v;
  for(int i=0;i<4;i++){
    vector<int> row;
    for(int j=0;j<4;j++){
      int in;
      scanf("%d",&in);
      row.push_back(in);
      if(!in) continue;
      g.adj[i].push_back(j);
    }
    v.push_back(row);
  }
  for(int i=0;i<4;i++){
    for(int j=i;j<4;j++){
      edges+=v[i][j];
    }
  }
  g.DFS(0);
  int c=0;
  for(auto x:g.visited)c+=x.second;
  if(c==4&&edges==3)printf("Yes\n");
  else printf("No\n");
}
