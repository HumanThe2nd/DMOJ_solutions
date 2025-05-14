/*
OTHS Coding Competition 3 P3 - Domain Expansion
Author: Dan Shan
Date: 2025-02-06
store the start and end of each domain in a map
iterate the relevant coordinates while keeping a priority queue of all current strengths
for each interval end, add the interval length to the strongest domain user
Note: Inefficient solution but passes
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    vector<ll> c(n+1,0); // each sorcerer
    map<ll, vector<ll>> m; // start and end of each domain
    unordered_map<ll, ll> p; // power level to respective sorceror
    for(int i=0;i<n;i++){
        ll l,r,ai;
        cin >> l >> r >> ai;
        p[ai]=i;
        m[l].emplace_back(ai);
        m[r+1].emplace_back(-ai);
    }
    set<ll> cur;
    ll l=m.begin()->first; cur.insert(0); // placeholder max
    for(auto x: m){
        ll strongest=*cur.rbegin(),cord=x.first;
        if(strongest) c[p[strongest]]+=cord-l; // non empty maximum
        l=cord;
        for(auto y: x.second){
            if(y>0) cur.insert(y);
            else cur.erase(-y);
        }
    }
    cout << c[0];
    for(int i=1;i<n;i++) cout << " " << c[i];
    cout << "\n";
}
