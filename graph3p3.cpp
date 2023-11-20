//============================================================================
// Name        : Graph Contest 3 P3 - Cable TV
// Author      : Dan Shan
//============================================================================
// Goal: find minimum  prioritizing danger followed by costs
// Approach: - make danger a large const so its top priority before costs
//           - minimum spanning tree with Prim's algorithm to find minimum
//           - seperate the danger and costs when printing using modulus
#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int, vector<pair<int, int>>> adj; // value & cost + danger

void prim(int V, int s=1){ // takes in starting node
	int c=0; // minimum cost
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> key(V+1, INT_MAX);
	vector<int> weight(V+1, INT_MAX);
	vector<int> parent(V+1,-1);
	vector<bool> inMST(V+1,0);
	pq.push(make_pair(0,s));
	key[s]=0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		inMST[u] = 1;
		for(auto x: adj[u]){
			int v = x.first, w = x.second;
			if(!inMST[v]&&key[v]>w){
				key[v] = w;
				weight[v] = x.second;
				pq.push(make_pair(key[v],v));
				parent[v] = u;
			}
		}
	}
	for(int i=0;i<=V;i++){
		if(parent[i] != -1){
			c += weight[i];
		}
	}
	printf("%d %d\n",(int)(c/1e7),c%((int)1e7));
}

int main(){
scanf("%d %d",&n,&m);
for(int i=0;i<m;i++){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	adj[a].push_back(make_pair(b,c+d*1e7)); // link nodes with cost + danger
	adj[b].push_back(make_pair(a,c+d*1e7));
}
prim(n,1);
}
