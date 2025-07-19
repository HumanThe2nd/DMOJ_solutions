/*
DMOPC '19 Contest 5 P1 - Conspicuous Cryptic Checklist
Author: Dan Shan
Date: 2025-07-19
1. Store valid materials in set
2. Count recipes with all it's materials in the set
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,c=0;
    cin >> n >> m;
    unordered_set<string> s;
    while(n--){
        string si;
        cin >> si;
        s.insert(si);
    }
    for(int i=0;i<m;++i){
        int ai,f=1;
        cin >> ai;
        while(ai--){
            string si;
            cin >> si;
            if(s.find(si)==s.end()) f=0;
        }
        c+=f;
    }
    cout << c << "\n";
}
