/*
South African Computer Olympiad 2008 Day 1 Problem 3 - Visiting Grandma
Author: HumanThe2nd
Date: 2025-03-26
Run Dijkstra's with edges with and without cookies

number of paths:
if new minimum found, reset
otherwise add paths of last node

Note: update cookie state on cookie nodes, if updating while transitioning it will fail case 10
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ai;
            cin >> ai;
            adj[i][j]=ai;
        }
    }
    int t;
    cin >> t;
    vector<bool> a(n,0);
    vector<vector<int>> d(n,vector<int>(2,2e9)),p(n,vector<int>(2,0));
    for(int i=0;i<t;i++){
        int ai;
        cin >> ai;
        a[ai-1]=1;
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; // distance, node
    pq.push({0,0,0});
    d[0][0]=0; p[0][0]=1;
    while(pq.size()){
        auto [di,ni,ci]=pq.top();
        pq.pop();
        if(di>d[ni][ci]) continue;
        for(int i=0;i<n;i++){
            if(i==ni) continue;
            int df=di+adj[ni][i],cii=(ci||a[ni]); // new distance & cookie state
            if(df<d[i][cii]){
                d[i][cii]=df;
                p[i][cii]=p[ni][ci];
                pq.push({df,i,cii});
            }
            else if(df==d[i][cii]){
                p[i][cii]+=p[ni][ci];
                p[i][cii]%=1000000;
            }

        }
    }
    cout << d[n-1][1] << " " << p[n-1][1] << "\n";
}
