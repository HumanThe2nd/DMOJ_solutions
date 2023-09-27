#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	int x,y,e;
	unordered_map<int, unordered_set<int>> adj;
	scanf("%d %d",&x,&y);
	e = x*y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			int in;
			scanf("%d",&in);
			adj[i*j].insert(in);
		}
	}
	bool possible=0;
	queue<int> queue;
	unordered_set<int> visited;
	queue.push(1);
	while(!queue.empty()){
		int n = queue.front();
		queue.pop();
		for(auto x: adj[n]){
			if(x==e){possible=1;break;}
			if(adj.find(x)!=adj.end()&&visited.find(x)==visited.end()){
				queue.push(x);
				visited.insert(x);
			}
		}
	}
	if(possible) printf("yes\n");
	else printf("no\n");
}
