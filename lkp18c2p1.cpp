/*

LKP '18 Contest 2 P1 - Food Lines
Author: Dan Shan
Date: 2025-07-06
Priority queue to query minimum in log(n) time
Time Complexity: O(M*log(N))
Note: Brute force should also pass
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<n;++i){
        int ai;
        cin >> ai;
        pq.emplace(ai);
    }
    while(m--){
        int ai=pq.top(); pq.pop();
        cout << ai << "\n";
        pq.emplace(ai+1);
    }
}
