//============================================================================
// Name        : TSOC '15 Contest 1 #5 - Giant Ants
// Author      : Dan Shan
//============================================================================
// Goal: see if possible to travel between 2 nodes with nodes adj to ant nodes
// 		 being removed every 4 moves
// Approach: run BFS and every time to depth reaches 4 mark the adj of all
// ants visited and update ant location
// Run a main BFS and one for each ant
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	bool visited[n+1];
	memset(visited,0,n+1);
	unordered_map<int, set<int>> adj;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].insert(y);
		adj[y].insert(x);
	}
	int w,dist=0,ant_moves=0;
	scanf("%d",&w);
	queue<int> a,ad;
	for(int i=0;i<w;i++){
		int ant;
		scanf("%d",&ant);
		a.push(ant);
		ad.push(0);
		visited[ant]=1;
	}
	queue<int> queue,t;
	queue.push(1); t.push(0);
	while(!queue.empty()){
		int d=queue.front(),ti=t.front();
		if(d==n){dist=ti;break;}
		if(d/4>ant_moves){ant_moves++;
		while(!a.empty()){
			int an = a.front(),adist=ad.front();
			a.pop();ad.pop();
			if(adist==ant_moves)break;
			for(auto x:adj[an]){
				if(!visited[x]){
				visited[x]=1;
				a.push(x);
				ad.push(adist+1);
				}
			}
		}
		}
		queue.pop(); t.pop();
		for(auto x:adj[d]){
			if(!visited[x]){
				visited[x]=1;
				queue.push(x);
				t.push(ti+1);
			}
		}
	}
	if(!dist)printf("sacrifice bobhob314\n");
	else printf("%d\n",dist);
}
