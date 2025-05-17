// COCI '19 Contest 6 #2 Birmingham
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m,q,k;
cin >> n >> m >> q >> k;
queue<int> qn,qd;
vector<vector<int>> adj(n+1);
int v[n+1],dis[n+1],c=1;
for(int i=0;i<=n;i++)v[i]=-1;
for(int i=0;i<n;i++){
	for(int j=0;j<i*k;j++){
		dis[c]=i;
		c++;
		if(c>n)break;
	}
	if(c>n)break;
} dis[0]=0;
for(int i=0;i<q;i++){
	int a;
	cin >> a;
	qn.emplace(a);
	qd.emplace(0);
}
for(int i=0;i<m;i++){
	int a,b;
	cin >> a >> b;
	adj[a].emplace_back(b);
	adj[b].emplace_back(a);
}
while(!qn.empty()){
	int ni=qn.front(),di=qd.front();
	qn.pop(); qd.pop();
	if(v[ni]<0)v[ni]=dis[di];
	for(int x: adj[ni]){
		if(v[x]<0){
			qn.emplace(x);
			qd.emplace(di+1);
		}
	}
}
for(int i=1;i<=n;i++)printf("%d ",v[i]);
}
