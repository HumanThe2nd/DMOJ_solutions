/*
IOI '20 P2 - Connecting Supertrees
Author: Dan Shan
Date: 2025-06-30

1. DSU to group nodes where (paths[i][j] > 0).
2. For each group:
   a. Use another DSU to group where (paths[i][j] == 1).
3. Connect each of these subgroups in individual chains (branches)
3. If branches > 2, connect them in a cycle.
   - Exactly 2 branches: invalid.
   - Exactly 1 branch: full subgraph.
5. Ex. Invalids:
   - Inconsistent connections (e.g., paths[i][j] == 1 in different components)
   - Missing connections
   - any paths[i][j] == 3

Fun note: 
as of this note, you can earn 4/100 points by returning 0 for all cases
(I doubt it's intentional)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int p[10001],r[10001]; // pre-initialization
int f(int ai){ // find
    if(p[ai]==ai) return ai;
    return p[ai]=f(p[ai]);
}
void u(int ai, int bi){ // union
    ai=f(ai);
    bi=f(bi);
    if(r[ai]<r[bi]){ // path compression
        p[ai]=bi;
    }
    else {
        if(r[ai]==r[bi]) r[ai]++;
        p[bi]=p[ai];
    }
}
int construct(vector<vector<int>> paths){
    int n=paths.size();
    vector<vector<int>> res(n,vector<int>(n,0)),trees(n);
    for(int i=1;i<n;i++) p[i]=i; // initialize parent array
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(paths[i][j]==3) return 0;
            if(paths[i][j]) u(i,j);
        }
    }
    for(int i=0;i<n;++i){ // DSU -> vectors
        trees[f(i)].emplace_back(i);
    }
    for(int i=0;i<n;++i){
        int si=trees[i].size(),sz=0;
        if(si<2) continue; // skip single nodes
        for(int j=0;j<n;++j) p[j]=j,r[j]=0; // reset DSU
        for(auto x: trees[i]){
            for(int y: trees[i]) {
                if(!paths[x][y]) return 0; // invlaid component
                if(paths[x][y]==1) u(x,y);
            }
        }
        vector<vector<int>> t2(n); // DSU -> vectors
        vector<int> v(n,0),roots;
        for(auto x:trees[i]) {
            int pi=f(x);
            t2[pi].emplace_back(x);
            if(!v[pi]) ++sz,roots.emplace_back(pi);
            v[pi]=1;
        }
        if(sz==2) return 0;
        for(auto x:trees[i])
            for(auto y: trees[i])
                if((paths[x][y]==1)!=(f(x)==f(y))) return 0; // invalid connection
        if(sz>2){
            for(int j=1;j<sz;++j) // build cycle with chains
                res[roots[j]][roots[j-1]]=res[roots[j-1]][roots[j]]=1;
            res[roots[0]][roots[sz-1]]=res[roots[sz-1]][roots[0]]=1;
        }
        for(int x=0;x<n;++x){
            if(t2[x].empty()) continue;
            for(int j=1;j<t2[x].size();++j){
                res[t2[x][j]][t2[x][j-1]]=res[t2[x][j-1]][t2[x][j]]=1;
            }
        }
    }
    build(res);
    return 1;
}
