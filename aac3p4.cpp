/*
An Animal Contest 3 P4 - Monkey Mayhem
Author: Dan Shan
Date: 2025-01-03
increasing time is equivalent to lowewring the index of the monkey up its respective axis
store each new row index in a map
for each new column index check for the respective row index
upon using an index, decrement its frequency as it can't collide again
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> f; // number of each start point
    int n,m,res=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int ai;
        cin >> ai;
        if(ai<0) continue; // can't collide
        f[i-ai]++;
    }
    for(int i=1;i<=m;i++){
        int ai;
        cin >> ai;
        if(ai<0) continue;
        ai=i-ai;
        if(f.find(ai)==f.end()) continue;
        f[ai]--; res++;
        if(!f[ai]) f.erase(ai);
    }
    cout << res << "\n";
}
