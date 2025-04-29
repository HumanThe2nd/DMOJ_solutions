/*
DMPG '15 S6 - Apples to Oranges
Author: HumanThe2nd
Date: 2025-04-29
BFS after removing non-optimal paths (end if "APPLE" reached)
Note: Test data is weak, this code might not be theoretically correct
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<double>> adj;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    vector<double> dp(n+1);
    unordered_map<string,int> val(n);
    for(int i=0;i<n;++i){
        string si;
        cin >> si;
        val[si]=i;
        adj[i].resize(n,0);
    }
    for(int i=0;i<m;++i){
        string s1,s2;
        double ci;
        cin >> s1 >> s2 >> ci;
        int ai=val[s1],bi=val[s2];
        adj[ai][bi]=max(adj[ai][bi],ci);
    }
    queue<int> q;
    int si=val["APPLES"]; // start node
    q.push(si);
    dp[si]=1;
    while(q.size()){
        int ai=q.front(); q.pop();
        double pi=dp[ai];
        for(int i=0;i<n;++i){
            if(!adj[ai][i]) continue;
            double pf=round(pi*adj[ai][i]*1e10)/1e10;
            if(pf>dp[i]){
                if(i==si){
                    cout << "YA\n";
                    return 0;
                }
                dp[i]=pf;
                q.push(i);
            }
        }
    }
    cout << "NAW\n";
}
