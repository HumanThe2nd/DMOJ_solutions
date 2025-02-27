//============================================================================
// Name        : COCI '18 Contest 4 #2 Wand
// Author      : Dan Shan
//============================================================================
// Goal: print out nodes connected to node 1 in direct graph
// Approach: connecting a directed graph and bfs from 1 any node touched including 1
//           can be a winner, 1 starts untouched
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	unordered_map<int,unordered_set<int>> adj;
    scanf("%d %d",&n,&m);
	int v[n+1],t[n+1]; // v: visited nodes, t: if node is max in its graph
	for(int i=0;i<=n;i++){ // initialization
		v[i]=0; // none start visited
		t[i]=0; // all start not highest
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[b].insert(a);
	}
    queue<int> q; q.push(1);
    while(!q.empty()){
    	int ni = q.front();
    	q.pop();
    	for(auto x: adj[ni]){
    		if(!v[x]){
    			v[x]=1;
    			q.push(x);
    			t[x]=1; // node can be highest
    		}
    	}
    }
    // *important* edge case where 1 has no fights so it wins by default 
    if(adj[1].empty())t[1]=1;
    for(int i=1;i<=n;i++){
    	printf("%d",t[i]);
    }
}
