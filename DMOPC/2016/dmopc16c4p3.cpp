/*
DMOPC '16 Contest 4 P3 - Carnival Phantasm
Author: Dan Shan
Date: 2024-12-27
1 map of stand to its apples
1 vector of maps of distance to indexes (vector index represents type)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s,q;
    cin >> n >> s;
    vector<int> d(n+1); // index to distance
    unordered_map<int, set<int>> at; // stand to apple type
    vector<map<int, set<int>>> k(101); // apple type: distance->index
    for(int i=1;i<=n;i++){
        int di;
        cin >> di;
        d[i]=di;
    }
    while(s--){
        int si,ai; // index, type
        cin >> si >> ai;
        k[ai][d[si]].insert(si); // type, distance, index
        at[si].insert(ai);
    }
    cin >> q;
    while(q--){
        string si;
        cin >> si;
        if(si=="Q"){ // query
            int ki;
            cin >> ki;
            int k2=k[ki].begin()->first;
            if(k[ki].empty()||k[ki][k2].empty()) cout << "-1\n";
            else cout << *k[ki][k2].begin() << "\n";
        }
        else if(si=="S"){ // index xi stop selling type ki
            int xi,ki;
            cin >> xi >> ki;
            int di=d[xi];
            k[ki][di].erase(xi);
            if(k[ki][di].empty()) k[ki].erase(di);
            at[xi].erase(ki);
            if(at[xi].empty()) at.erase(xi);
        }
        else if(si=="A"){ // index xi starts selling type ki
            int xi,ki;
            cin >> xi >> ki;
            k[ki][d[xi]].insert(xi);
            at[xi].insert(ki);
        }
        else{ // xi moves to ki and stops selling
            int xi,ki;
            cin >> xi >> ki;
            for(auto ti: at[xi]){ // removes apple types
                k[ti][d[xi]].erase(xi);
                if(k[ti][d[xi]].empty()) k[ti].erase(d[xi]);
            }
            at.erase(xi);
            d[xi]=ki; // relocate
        }
    }
}
