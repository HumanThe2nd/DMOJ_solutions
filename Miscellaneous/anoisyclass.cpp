//============================================================================
// Name        : A Noisy Class
// Author      : Dan Shan
//============================================================================
// Goal: cycle detection
// Approach: check for cycle using DFS cycle checker
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
bool visited[10001], recStack[10001];

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < adj[v].size(); ++i) {
            if (!visited[adj[v][i]] && isCyclicUtil(adj[v][i]))
                return true;
            else if (recStack[adj[v][i]])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int V) {
    memset(visited, false, sizeof(visited));
    memset(recStack, false, sizeof(recStack));
    for (int i = 0; i < V; ++i)
        if (isCyclicUtil(i))
            return true;

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    if (isCyclic(V))
        printf("N\n");
    else
        printf("Y\n");

    return 0;
}
