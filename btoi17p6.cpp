/*
Baltic OI '17 P6 - Cat in a tree
Author: Dan Shan
Date: 2024-11-24
Tree dp with modulus to account for d
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int dp[200001],t,d,c;
void dfs(int n){
    vector<int> q;
    for(auto x: adj[n]){
        dfs(x);
        q.emplace_back(dp[x]+1);
    }
    int l=0,s=q.size()-1;
    sort(q.begin(),q.end());
    while(l<s&&q[l]+q[l+1]<d){
        l++; c--;
    }
    if(l<=s) dp[n]=q[l]%d;
    if(!dp[n]) c++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> d;
    adj.resize(t+1);
    for(int i=1;i<t;i++){
        int a;
        cin >> a;
        adj[a].emplace_back(i);
    }
    dfs(0);
    cout << c;
}
