//============================================================================
// Name        : Graph Contest 2 P3 - Trees
// Author      : Dan Shan
//============================================================================
// Goal: Minimum edges to remove to make a graph a forest or tree
// Approach: DFS to count cycles and the amount of edges to break is that value
#include<iostream>
int v[1000],c,n, adj[1000][1000];; // visited array and counter
void dfs(int s, int p) {
    v[s] = 1;
    for(int i = 0; i < n; i++) {
        if(adj[s][i]) {
            if(v[i] == 0) dfs(i, s);
            else if(i != p) c++;
        }
    }
}
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		scanf("%d",&adj[i][j]);
	}
}
for(int i=0;i<n;i++){
	if(!v[i]) dfs(i,-1);
}
printf("%d\n",c/2); // cycles are counted twice
}
