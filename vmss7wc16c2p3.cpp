/*
VM7WC '16 #2 Gold - GGG
Author: Dan Shan
Date: 2025-05-29
Longest common subsequence with distinct integers
1. Map values of both arrays to index in one
2. Maintain an array of the LCS
For each element in order:
1. add to the LCS if index is greater
2. replace the first lowest element otherwise
Time Complexity: O(N*log(N))
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n;
    vector<int> ind(1e6+1,-1);
    for(int i=0;i<n;++i) {
        int ai;
        cin >> ai;
        ind[ai]=i;
    }
    cin >> m;
    vector<int> a;
    for(int i=0;i<m;++i){
        int ai;
        cin >> ai;
        if(ind[ai]>=0) a.emplace_back(ind[ai]); // element in both arrays
    }
    vector<int> res;
    for(int x: a){
        auto it=lower_bound(res.begin(),res.end(),x);
        if(it==res.end()) res.emplace_back(x); // add element
        else *it=x; // replace element
    }
    cout << res.size() << "\n";
}
