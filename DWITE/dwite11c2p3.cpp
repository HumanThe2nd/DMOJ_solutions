/*
DWITE '11 R2 #3 - Anonymous Shopping
Author: Dan Shan
Date: 2024-02-17
Observation: store number and student names are useless
Map all ids to products, store duplicates in a set
for each student check if their id occurs and no duplicates
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int ti=0;ti<5;ti++){
        int n,m,c=0;
        cin >> n >> m;
        unordered_map<string, string> s;
        unordered_set<string> f; 
        for(int i=0;i<n;i++){
            int a;
            string b,c;
            cin >> a >> b >> c;
            if(s.find(b)==s.end()) s[b]=c;
            else if(s[b]!=c) f.insert(b);
        }
        for(int i=0;i<m;i++){
            string a,b;
            cin >> a >> b;
            if(s.find(b)!=s.end()&&f.find(b)==f.end()) c++; // connection & unique
        }
        cout << c << "\n";
    }
}
