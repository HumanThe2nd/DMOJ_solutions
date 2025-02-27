/*
An Animal Contest 7 P2 - Squirrel Structures
Author: Dan Shan
Date: 2025-02-13
Connect all nodes to their grandparent
Note: trees are undirected (2 hours wasted debugging)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1),a2(n+1); // second adjcaceny map
    vector<int> s={1}; // starting nodes
    for(int i=1;i<n;i++){
        int ai,bi;
        cin >> ai >> bi;
        adj[bi].emplace_back(ai);
        adj[ai].emplace_back(bi);
    }
    for(auto y: adj[1]){
        queue<int> qn,qp,qg; // node, parent, grandparent
        s.emplace_back(y);
        qn.emplace(y); qp.emplace(1); qg.emplace(-1);
        while(!qn.empty()){
            int ni=qn.front(),pi=qp.front(),gi=qg.front();
            qn.pop(); qp.pop(); qg.pop();
            if(gi>0) a2[gi].emplace_back(ni); // make edge
            for(auto x: adj[ni]){
                if(x==pi) continue; // can't move backwards
                qn.emplace(x); qp.emplace(ni); qg.emplace(pi);
            }
        }
    }
    int k=s.size();
    cout << k << "\n";
    for(auto y: s){
        queue<int> q,qr,qr2;
        q.emplace(y);
        while(!q.empty()){
            int ni=q.front();
            q.pop();
            for(auto x: a2[ni]){
                qr.emplace(ni);
                qr2.emplace(x);
                q.emplace(x);
            }
        }
        cout << qr.size()+1 << "\n";
        while(!qr.empty()){
            cout << qr.front() << " " << qr2.front() << "\n";
            qr.pop(); qr2.pop();
        }
    }
}
