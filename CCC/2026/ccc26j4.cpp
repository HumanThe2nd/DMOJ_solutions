/*
CCC '26 J4 - Snail Path
Author: Dan Shan
Date: Mar 29, 2026

Ugly implementation for a J4

Approach:
- hash every visited coord as distinct combinations of the 2 coordinates in a set
- Brute force the simulation and count revisited squares
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
inline long long encode(long long x, unsigned int y) {
    return (x << 32) ^ y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x = 0, y = 0, res = 0;
    cin >> n;
    unordered_set<long long> v;
    v.reserve(1000000); // optional speed optimizations
    v.max_load_factor(0.7);
    v.emplace(encode(0, 0)); // initial pos
    while(n--){
        string si;
        cin >> si;
        char dir = si[0]; // move direction
        int depth = 0; // # of moves
        for(int i = 1; i < si.size(); ++i)
            depth = depth * 10 + (si[i] - '0');
        int xi = 0, yi = 0; // represent movements as a unit vector (ex. (0, 1))
        if(dir == 'N') ++yi;
        else if(dir == 'S') --yi;
        else if(dir == 'W') ++xi;
        else --xi;
        for(int i = 0; i < depth; ++i){
            x += xi;
            y += yi;
            long long cur_pos = encode(x, y);
            if(v.find(cur_pos) != v.end()) ++res; // revisit -> add
            else v.emplace(cur_pos); // 1st visit
        }
    }
    cout << res << "\n";
}
