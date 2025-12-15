/*
CCC '21 S5 - Math Homework
Author: Dan Shan
Date: 2025-12-15

Observation: Min valid Ai: LCM of all Zi that covers it
Part A: Create array
1. Difference array: mark intervals of each GCD value 
2. Build PSA to find GCD values at each index
   Set r[i] = LCM of values at psa[i]
Part B: Check Validity
1. Build sparse table for GCD between points
2. Validate all queries (if any fail, array is invalid)

Note: Also uploaded a slightly faster C solution with small optimizations
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n+1), q(m);
    for(int i = 0; i < m; ++i){
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        s[--xi].emplace_back(zi);
        s[yi--].emplace_back(-zi);
        q[i] = {xi, yi, zi};
    }
    vector<int> psa(17, 0), r(n);
    for(int i = 0; i < n; ++i){
        for(auto x: s[i]){
            if(x > 0) ++psa[x];
            else --psa[-x];
        }
        int res = 1;
        for(int j = 2; j < 17; ++j) if(psa[j]) res = lcm(res, j);
        r[i] = res;
    }
    int log = __lg(n) + 1; // Build sparse table
    vector<vector<int>> sp(log, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) sp[0][i] = r[i];
    for(int i = 1; i < log; ++i){
        int jmp = 1 << (i-1);
        for(int j = 0; j < n - (1 << i) + 1; ++j) sp[i][j] = gcd(sp[i-1][j], sp[i-1][j+jmp]);
    }
    for(int i = 0; i < m; ++i){ // Verify 
        int bit = __lg(q[i][1] - q[i][0] + 1);
        if(gcd(sp[bit][q[i][0]], sp[bit][q[i][1] - (1 << bit) + 1]) != q[i][2]){
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << r[0];
    for(int i = 1; i < n; ++i) cout << " " << r[i];
    cout << "\n";
}
