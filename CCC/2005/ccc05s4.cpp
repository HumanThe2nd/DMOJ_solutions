//============================================================================
// Name        : CCC '05 S4 - Pyramid Message Scheme
// Author      : Dan Shan
//============================================================================
// Goal: find difference in BFS times and levels d
// Approach: BFS track amounts of visited and # of levels and return difference
#include<bits/stdc++.h>
using namespace std;
int main(){
int l;
cin >> l;
for(int i=0;i<l;i++){
	int n;
	cin >> n;
	unordered_map<string, set<string>> adj;
	unordered_set<string> visited;
	string start=" ";
for(int j=0;j<n/2;j++){
	string a, b;
	cin >> a >> b;
	start = b;
	adj[a].insert(b);
	adj[b].insert(a);
}
queue<string> q;
queue<int> depth;
int m=0, c=0,s;
for(auto x:adj)c+=10;
q.push(start); depth.push(10);
visited.insert(start);
while(!q.empty()){
	string name = q.front();
	int di = depth.front();
	m = max(m,di);
	q.pop(); depth.pop();
	for(string x: adj[name]){
		if(visited.find(x)==visited.end()){
			visited.insert(x);
			q.push(x);
			depth.push(di+10);
		}
	}
}
s = (c-m)*2;
printf("%d\n",s);
}
}
