//============================================================================
// Name        : SAC '22 Code Challenge 5 Junior P4 - Course Requirements
// Author      : Dan Shan
//============================================================================
// Goal: sorting nodes in acyclic directed graph
// Approach: Topo sort into queue
#include <bits/stdc++.h>
int vis[200001];
std::unordered_map<int, std::unordered_set<int>> adj;
std::queue<int> q;
void DFS(int v){
	for(auto x:adj[v]){
		if(!vis[x]) {
			vis[x]=1;
			DFS(x);
		}
	}
	q.push(v);
}
void topo(int n){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			DFS(i);
		}
	}
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int c;
    	scanf("%d",&c);
    	for(int j=0;j<c;j++){
    		int a;
    		scanf("%d",&a);
    		adj[i].insert(a);
    	}
    }
   topo(n);
while(!q.empty()){
	printf("%d ",q.front());
	q.pop();
}
}

