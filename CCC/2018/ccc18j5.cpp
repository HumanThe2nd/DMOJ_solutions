//============================================================================
// Name        : CCC '18 J5 - Choose your own path
// Author      : Dan Shan
//============================================================================
// Goals: -check if all pages connected
// 	   	  -find shortest path
#include <bits/stdc++.h>
using namespace std;
class graph{
public:
	unordered_map<int, unordered_set<int>> adj;
	int BFS(); bool DFS(int m);
};
int graph::BFS(){ // shortest path
	unordered_map<int, bool> visited;
	int d=1,s=1;
	queue<int> queue,dist;
	queue.push(s);
	dist.push(d);
	visited[s]=1;
	while(!queue.empty()){
		s = queue.front();
		d = dist.front();
		queue.pop();
		dist.pop();
	if(adj[s].empty()) return d;
	for(auto x:adj[s]){
		if(!visited[x]){
			visited[x]=1;
			queue.push(x);
			dist.push(d+1);
		}
	}
	}
	return d;
}
bool graph::DFS(int m){ // checks if graph is connected
	int s=1;
	unordered_map<int, bool> visited;
		queue<int> queue;
		queue.push(s);
		visited[s]=1;
		while(!queue.empty()){
			s = queue.front();
			queue.pop();
		for(auto x:adj[s]){
			if(!visited[x]){
				visited[x]=1;
				queue.push(x);
			}
		}
		}
	s = visited.size();
	return (s==m); // if all pages visited
}
int main() {
	graph g;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int in;
			scanf("%d",&in);
			g.adj[i].insert(in);
		}
	}
	int s = g.BFS();
	if(g.DFS(n))printf("Y\n%d\n",s);
	else printf("N\n%d\n",s);
}
