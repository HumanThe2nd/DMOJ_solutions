/*
CCO '17 P5 - Professional Network
Author: Dan Shan
Date: 2025-07-03

1. sort network by non-increasing connections (ai), tiebreaken by non-decreasing costs (bi) 
2. start from the back of array, adding each cost to a pq, while insufficient friends, use the pq min
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
class con{
    public:
    int ai,bi;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,f=0,c=0;
    cin >> n;
    vector<con> net; // min ai
    vector<int> v(n,0); // visited connections
    for(int i=0;i<n;++i) {
        int ai,bi;
        cin >> ai >> bi;
        if(!bi) ++f;
        else net.push_back({ai,bi});
    }
    sort(net.begin(),net.end(),[&](con c1, con c2){return (c1.ai==c2.ai)?(c1.bi>c2.bi):(c1.ai<c2.ai);});
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=net.size()-1;i>=0;--i){
        pq.emplace(net[i].bi);
        while(net[i].ai>f+i){
            c+=pq.top(); pq.pop();
            ++f;
        }
    }
    cout << c << "\n";
}
