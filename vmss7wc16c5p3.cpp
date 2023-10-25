//============================================================================
// Name        : VM7WC '16 #5 Gold - Jayden Studies Trees
// Author      : Dan Shan
//============================================================================
// Goal: find maximum distance between 2 nodes in a tree
// Approach: BFS twice once to find farthest node and a second to find next farthest
//			 and return distance between them
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m = 0; // m: furthest dist from starting node
	scanf("%d",&n);
	vector<vector<int>> adj(n+1);
	vector<int> v(n+1, 0);
	for(int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> queue(n+1), dist(n+1);
	int front = 0, end = 0, s = 1, b1 = 1;
	v[s] = 1;
	queue[end] = s; dist[end++] = 0;
	while(front != end){
		int di = dist[front];
		s = queue[front++];
		if(di > m){m = di; b1 = s;} // set bound 1 to furthest node for next BFS
		for(int a : adj[s]){
			if(!v[a]){
				v[a] = 1;
				dist[end] = di + 1;
				queue[end++] = a;
			}
		}
	}
	front = 0, end = 0; // second BFS from furthest node
	fill(v.begin(), v.end(), 0); // clear visited arr
	v[b1] = 1;
	queue[end] = b1; dist[end++] = 0;
	while(front != end){
		int di = dist[front];
		s = queue[front++];
		if(di > m) m = di; // find furthest node
		for(int a : adj[s]){
			if(!v[a]){
				v[a] = 1;
				dist[end] = di + 1;
				queue[end++] = a;
			}
		}
	}
	printf("%d\n",m);
}
