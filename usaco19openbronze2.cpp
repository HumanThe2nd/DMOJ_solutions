// USACO 2019 Open Contest Bronze P2 - Milk Factory
// By: Dan Shan
// BFS
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> adj;
int main(){
int n;
scanf("%d",&n);
int cnt[n+1];
for(int i=0;i<=n;i++)cnt[i]=0;
for(int i=1;i<n;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	adj[a].push_back(b);
}
for(int i=1;i<=n;i++){
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int ni = q.front();
		q.pop();
		for(auto a: adj[ni]){
			cnt[a]++;
			q.push(a);
		}
	}
}
for(int i=1;i<=n;i++){
	if(cnt[i]==n-1){
		printf("%d\n",i);
		return 0;
	}
}
printf("-1\n");
}
