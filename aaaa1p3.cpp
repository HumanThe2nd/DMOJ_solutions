/*
AAAA 1 P3 - Topographical Sort
Author: Dan Shan
Date: 2025-12-25

Subtask 1
Iterate all islands in descending order of their height:
    if both sides are islands -> merge (remove island)
    else if neither sides are islands -> create new (add island)
    else -> extend island (no change)

Subtask 2
Iterate each height in descending order:
    remove 'x' island(s) -> put island between a gap 'x' times
    add 'x' island(s) -> add isolated island of set height 'x' times
    Return impossible if (next add/remove index out of bounds or invalid removal index)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t >> n;
    int h = n; // height iterator
    vector<pair<int, int>> a(n); // index, height (or island count for T = 2)
    vector<int> v(n+1, 0), res(n+1, 0);
    for(int i = 0; i < n; ++i){
        a[i].first = i;
        cin >> a[i].second;
    }
    if(t == 1){
        sort(a.begin(), a.end(),[&](auto ai, auto bi){return ai.second > bi.second;});
        for(int i = 0; i < n; ++i){
            int ai = a[i].first, hi = a[i].second, adj = 0;
            while(h > hi) res[h-1] = res[h], --h;
            if(ai && v[ai-1]) ++adj; // left adj
            if(ai <= n && v[ai+1]) ++adj; // right adj

            if(adj == 2) --res[h];
            else if(adj == 0) ++res[h];
            v[ai] = 1;
        } while(h > 0) res[h-1] = res[h], --h;
    }
    else{ // task 2
        int islands = 0, b = 1, r = 2; // b: build index, r: remove index
        for(int i = n-1; i >= 0; --i){
            int ci = a[i].second;
            while(islands > ci){ // prune
                if(r >= n) return !puts("-1");
                while(r && r < n && res[r]) ++r;
                if(!r || !res[r - 1] || !res[r + 1]) return !puts("-1"); // no valid placements left
                res[r++] = i + 1;
                while(r <= n && res[r]) ++r; // find next gap (or edge)
                --islands;
            }
            while(islands < ci){ // add islands
                if(b > n) return !puts("-1");
                res[b++] = i + 1;
                while(b <= n && (res[b-1] || res[b])) ++b; // find next isolated slot
                ++islands;
            }
        }
    } cout << res[1];
    for(int i = 2; i <= n; ++i) cout << " " << res[i];
    cout << "\n";
}
