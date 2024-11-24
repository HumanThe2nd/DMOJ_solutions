// CCC '09 S4 - Shop and Ship
// By: Dan Shan
// Implement Dijkstras then for each node add its respective pencil cost and take the minimum
#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int main() {
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int n,t,k,d,mc=1e9;
cin >> n >> t;
vector<vector<pi>> adj(5001);
for(int i=0;i<t;i++){ // edges
	int x,y,c;
	cin >> x >> y >> c;
	adj[x].push_back({y,c});
	adj[y].push_back({x,c});
}
cin >> k;
int mn[5001],cst[5001];
for(int i=0;i<5001;i++)
	mn[i]=1e9, cst[i]=1e9;
for(int i=0;i<k;i++){
	int z,p;
	cin >> z >> p;
	cst[z]=p;
}
cin >> d;
priority_queue<pi, vector<pi>, greater<pi>> pq;
pq.push({0,d});
mn[d]=0;
while(!pq.empty()){
	int v = pq.top().second,dv = pq.top().first;
	pq.pop();
	if(dv!=mn[v])continue;
	for(auto edge: adj[v]){
		int ti = edge.first, len = edge.second;
		if(mn[v]+len<mn[ti]){
			mn[ti]=mn[v]+len;
			pq.push({mn[ti],ti});
		}
	}
}
for(int i=1;i<5001;i++){
	if(mn[i]==1e9) continue;
	else mc = min(mc,mn[i]+cst[i]);
}
cout << mc << "\n";
}
