//============================================================================
// Name        : CCO '01 P1 - The Monkey Dance
// Author      : Dan Shan
//============================================================================
// Goal: given multiple cycles find time it takes for all to finish simultaneously
// Approach: find number of cycles and the length of each using DFS then return LCM of lengths
#include<stdio.h>
#include<string.h>

long long int gcd(int a,int b){
    if(!a) return b;
    return gcd(b%a,a);
}

long long int lcm(int a, int b){
    return(a/gcd(a,b))*b;
}

void dfs(int node, int adj[][101], int visited[], int cycle[], int* cycleIndex){
    visited[node] = 1;
    cycle[(*cycleIndex)++] = node;
    for(int i=1; i<=101; i++){
        if(adj[node][i] && !visited[i]){
            dfs(i, adj, visited, cycle, cycleIndex);
        }
    }
}

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n) break;

        int adj[101][101], visited[101], cycles[101];
        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));
        memset(cycles,0,sizeof(cycles));

        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a][b]=1;
        }

        int cc = 0; // Cycle count
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                int cycle[101], cycleIndex = 0;
                dfs(i, adj, visited, cycle, &cycleIndex);
                cycles[cc++] = cycleIndex;
            }
        }

        long long int t = cycles[0];
        for(int i=1;i<cc;i++){
            t=lcm(t,cycles[i]);
        }

        printf("%lld\n",t);
    }
}
