/*
CCC '18 S4 - Balanced Trees
Author: Dan Shan
Date: 2025-05-25
Recursively compute the number of balanced trees of size n
Observations / Optimizations:
1. DP (memoization) to avoid recomputation
2. Only sqrt(N) unique values of floor(N/i) -> group terms togetehr
3. group quotients by floor(N/i) and use multiplication to simplify
4. Use map to support large range of dp values 
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
unordered_map<int, ll> dp;
ll f(int n){
    if(n==1||n==2) return 1; // Base cases
    if(dp.find(n)!=dp.end()) return dp[n]; // precomputed value
    ll res=0,ni=n;
    while(ni>1){
        ll r=n/ni,l=n/(r+1); // r: floor(N/i), l: next position r changes
        res+=(ni-l)*f(r); // grouped contributions
        ni=l;
    }
    return dp[n]=res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << f(n) << "\n";
}
