// VM7WC '16 #3 Silver - Can Shahir even get there?!
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
class graph{
  public: unordered_map<int, list<int>> adj;
  void add(int s, int e);
  bool BFS(int s, int e);
};
void graph::add(int s, int e){
  adj[s].push_back(e);
  adj[e].push_back(s);
}
bool graph::BFS(int s, int e){
  bool reach = 0;
  unordered_set<int> visited;
  visited.insert(s);
  list<int> queue;
  queue.push_back(s);
  while(!queue.empty()){
    s = queue.front();
    if(s==e)reach=1;
    queue.pop_front();
  for(auto x: adj[s]){
    if(x==e)reach=1;
    if(visited.find(x)==visited.end()){
      visited.insert(x);
      queue.push_back(x);
    }
  }
  }
  return reach;
}
int main(){
  int n,m,a,b;
  scanf("%d %d %d %d",&n,&m,&a,&b);
  graph g;
  for(int i=0;i<m;i++){
    int s,e;
    scanf("%d %d",&s,&e);
    g.add(s,e);
  }
  if(g.BFS(a,b))printf("GO SHAHIR!\n");
  else printf("NO SHAHIR!\n");
}
