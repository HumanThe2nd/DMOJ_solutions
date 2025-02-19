/*
CCC '16 S3 - Phonomenal Reviews
Author: Dan Shan
Date: 2024-10-13
Given: graph (tree), relevant nodes
Find: shortest path between relevant nodes
Make all nodes between relevant nodes relevant as well.
Find number of relevant nodes and the diameter (longest path) in new graph. 
Optimal solution is given by n*2-diameter.
*/
#include<bits/stdc++.h>
using namespace std;
int a[100001],c=0,d=0,n1;
vector<vector<int>> adj;
void prune(int ni,int p){
	for(auto x: adj[ni]){
		if(x==p) continue;
		prune(x,ni);
		if(a[x]&&!a[ni]) {
			a[ni]=1; c++;
		}
	}
}
void dfs(int ni,int p,int di){
	for(auto x: adj[ni]){
		if(p!=x&&a[x]) dfs(x,ni,di+1);
	}
	if(di>d) {
		d=di; n1=ni;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,m,s;
	cin >> n >> m >> s;
	m--; a[s]=1; 
	n1=s; c=m;
	while(m--){
		int ai;
		cin >> ai;
		a[ai]=1;
	}
	adj.resize(n);
	for(int i=1;i<n;i++){
		int ai,bi;
		cin >> ai >> bi;
		adj[ai].emplace_back(bi);
		adj[bi].emplace_back(ai);
	}
	prune(s,-1);
	dfs(s,-1,0);
	dfs(n1,-1,0);
	printf("%d\n",2*c-d);
}
