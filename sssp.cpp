// Single Source Shortest Path
// By: Dan Shan
// Template Dijkstra's algorithm
#include<bits/stdc++.h>
#define MM 1000000000
using pi = std::pair<int,int>;
std::vector<std::vector<pi>> adj;
void dj(int s, std::vector<int>&d, std::vector<int>&p){
	int n = adj.size();
	d.assign(n,MM);
	p.assign(n,-1);
	d[s]=0;
	std::priority_queue<pi,std::vector<pi>,std::greater<pi>> q;
	q.push({0,s});
	while(!q.empty()){
		int v = q.top().second,dv = q.top().first;
		q.pop();
		if(dv!=d[v]) continue;
		for(auto edge: adj[v]){
			int to = edge.first, len = edge.second;
			if(d[v]+len<d[to]){
			d[to]=d[v]+len;
			p[to]=v;
			q.push({d[to],to});
		}
		}
	}
}
int main() {
std::ios::sync_with_stdio(0);
std::cin.tie(0);
int n,m;
std::cin >> n >> m;
adj.resize(n);
for(int i=0;i<m;i++){
	int a,b,c;
	std::cin >> a >> b >> c;
	a--; b--;
	adj[a].emplace_back(b,c);
	adj[b].emplace_back(a,c);
}
std::vector<int> d,p;
dj(0,d,p);
for(int i=0;i<d.size();i++){
	if(d[i]==MM)printf("-1\n");
	else printf("%d\n",d[i]);
}
}
