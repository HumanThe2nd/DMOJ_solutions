//============================================================================
// Name        : Mock CCC '18 Contest 5 J5/S3 - Directed Graph Connectivity
// Author      : Dan Shan
//============================================================================
// Goal: check if DFS is possible after removing any node
// Approach: for each node remove try DFS return result then put it back
#include <bits/stdc++.h>
using namespace std;
int main() {
queue<int> qx,qy;
unordered_map<int,unordered_set<int>> adj;
int n,m;
scanf("%d %d",&n,&m);
for(int i=0;i<m;i++){
	int s,t;
	scanf("%d %d",&s,&t);
	qx.push(s); qy.push(t);
	adj[s].insert(t);
}
while(!qx.empty()){ // try each path
	bool p=0;
	adj[qx.front()].erase(qy.front());
	int v[n+1];
	memset(v,0,sizeof(v));
	stack<int> s; s.push(1);
	v[1]=1;
	while(!s.empty()){
		int c = s.top(); s.pop();
		if(c==n) p=1;
		for(auto x: adj[c]){
			if(!v[x]){
				v[x]=1;
				s.push(x);
			}
		}
	}
	if(p)printf("YES\n");
	else printf("NO\n");
	adj[qx.front()].insert(qy.front());
	qx.pop();
	qy.pop();
}
}
