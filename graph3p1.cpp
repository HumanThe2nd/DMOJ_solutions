//============================================================================
// Name        : Graph Contest 3 P1 - Travelling Salesmen
// Author      : Dan Shan
//============================================================================
// Goal: Find time for a group of moving nodes to sweep a map
// Approach: graph everything and run BFS tracking depth of completion
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	int n,m,c=0;
	unordered_map<int, set<int>> adj;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].insert(b);
		adj[b].insert(a);
	}
	queue<int> queue,d;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		queue.push(in);
		d.push(0);
	}
	unordered_set<int> visited;
	while(!queue.empty()){
		int node = queue.front(),dist=d.front();
		queue.pop(); d.pop();
		c=max(c,dist);
		for(auto x: adj[node]){
			if(visited.find(x)==visited.end()){
				visited.insert(x);
				queue.push(x); d.push(dist+1);
			}
		}
	}
	printf("%d",c);
}
