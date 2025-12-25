/*
AAAA 1 P2 - Heavy-Light Composition
Author: Dan Shan
Date: 2025-12-24

Add gap between each pair of lights
subtract the max gap between either between 2 edges, 2 friends, or an edge and a friend
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, s = 0, c = 2e16; // subtract a gap between every light pair (or sentinels)
    cin >> n >> m;
    vector<ll> l(n+2), f(m), v(m, 0);
    l[n] = -1e16; l[n+1] = 1e16; // sentinels
    for(int i = 0; i < n; ++i) cin >> l[i];
    for(int i = 0; i < m; ++i) cin >> f[i];
    sort(l.begin(), l.end()); // not explicitly stated to be pre-sorted
    sort(f.begin(), f.end());
    for(int i = 0; i <= n; ++i){
        vector<ll> pts = {l[i]}; // start
        while(s < m && f[s] < l[i+1]) pts.emplace_back(f[s++]);
        pts.emplace_back(l[i+1]); // end
        ll ni = pts.size(), g = 0;
        for(int j = 1; j < ni; ++j) g = max(g, pts[j] - pts[j-1]);
        c -= g;
    }
    cout << c << "\n";
}
