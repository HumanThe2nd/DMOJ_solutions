//============================================================================
// Name        : CCC '13 S4 - Who is Taller?
// Author      : Dan Shan
//============================================================================
// Goal: figure out if possible to determine if a number is greater than anotehr given relative size or impossible
// Approach: graph all relative sizes and BFS if greater else BFS if lower if still no pathways found return unknown
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	unordered_map<int, set<int>> adj;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].insert(y);
	}
	queue<int> queue;
	bool visited[n+1],y=0;
	memset(visited,0,n+1);
	int p,q;
	scanf("%d %d",&p,&q);
	queue.push(p);
	while(!queue.empty()){
		int node = queue.front();
		queue.pop();
		for(auto x:adj[node]){
			if(x==q)y=1;
			if(!visited[x]){
				visited[x]=1;
				queue.push(x);
			}
		}
	}
	if(y)printf("yes\n");
	else{
		queue.push(q);
			while(!queue.empty()){
				int node = queue.front();
				queue.pop();
				for(auto x:adj[node]){
					if(x==p)y=1;
					if(!visited[x]){
						visited[x]=1;
						queue.push(x);
					}
				}
			}
		if(y)printf("no\n");
		else printf("unknown\n");
	}
}
