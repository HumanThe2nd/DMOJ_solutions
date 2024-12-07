/*
COCI '10 Contest 6 #4 Abeceda
Author: Dan Shan
Date: 2024-12-07
Treat first changing character in adjacent strings as a edge in directed graph
BFS to create path for alphabet
*/
#include <bits/stdc++.h>
using namespace std;
int n,c,c2,m,al[26];vector<int> adj[26]; bool vis[26]; queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(char c : s[i]) vis[c-'a'] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<min(s[i-1].size(),s[i].size());j++){
            if(s[i-1][j]!=s[i][j]){ // connect first distinct char in adjacent strings
                int u=s[i-1][j]-'a',v=s[i][j]-'a';
                adj[u].emplace_back(v); al[v]++;
                break;
            }
            if(j<s[i-1].size()-1&&j==s[i].size()-1) return printf("!\n")*0; // impossible
        }
    }
    for(int i=0;i<26;i++){
        c2+=vis[i];
        if(vis[i]&&!al[i]) q.push(i);
    }
    vector<int> order;
    while(!q.empty()){
        if(q.size()>1) m=1;
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v: adj[u]){
            if(--al[v]==0) q.push(v);
        }
    }
    if(order.size()!=c2) cout<<"!\n";
    else if(m) cout<<"?\n";
    else{
        for(auto x: order) cout<<(char)(x+'a');
    }
}
