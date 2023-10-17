//============================================================================
// Name        : CCC '07 S3 - Friends
// Author      : Dan Shan
//============================================================================
// Goal: input friend groups and check if 2 people are in the same group
// Approach: BFS to find the longest path before each point reaches its destination
#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
	unordered_map<int, unordered_set<int>> adj;
	unordered_set<int> visited;
	int BFS(int s,int e); // start, end, depth
};
int Graph::BFS(int s, int e) {
	queue<int> queue,dist;
	queue.push(s); dist.push(-1);
	while(!queue.empty()){
		int ni = queue.front(), di = dist.front();
		queue.pop(); dist.pop();
		if(ni==e)return di;
		for(auto x: adj[ni]){
			if(visited.find(x)==visited.end()){
				visited.insert(x);
				queue.push(x); dist.push(di+1);
			}
		}
	}
	return -1;
}
int main() {
	int n;
	scanf("%d",&n);
	Graph g;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		g.adj[a].insert(b);
	}
	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		if(!a&&!b)break;
		int f = g.BFS(a,b);
		if(f>-1)printf("Yes %d\n",f);
		else printf("No\n");
		g.visited.clear();
	}
}
