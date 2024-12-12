/*
USACO 2019 December Bronze P3 - Livestock Lineup
Author: Dan Shan 
Date: 2024
Alphabetical BFS
Each 2 cows can be seen as an edge in a graph
if a potential starting node has 2 adjacents, skip it as it is a middle node
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<string, vector<string>> adj;
  unordered_set<string> v; // used cows
  int n;
  cin >> n;
  while(n--){
    string s,s2;
    cin >> s >> s2 >> s2 >> s2 >> s2 >> s2;
    adj[s].emplace_back(s2);
    adj[s2].emplace_back(s);
  }
  vector<string> names = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup", "Sue"};
  sort(names.begin(),names.end());
  for(int i=0;i<8;i++){
    string si=names[i];
    if(v.find(si)!=v.end()||adj[si].size()>1) continue; // visited or middle node
    queue<string> q;
    q.emplace(si);
    v.insert(si);
    while(!q.empty()){
      string qi=q.front();
      q.pop();
      cout << qi << "\n";
      for(string x: adj[qi]){
        if(v.find(x)!=v.end()) continue;
        v.insert(x);
        q.emplace(x);
      }
    }
  }
}
