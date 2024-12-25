/*
Good Strategy
Author: Dan Shan
Date: 2024-12-24
map problems in ordered sets by balloon count
map each index to its current difficulty 
least balloons & highest index is max
most balloons & lowest index is min
no problems remain when both maps are emptied
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    map<int, set<int>> p; // p: balloons->problems
    map<int, int>  ind; // ind: problem->balloons
    for(int i=1;i<=n;i++) {
        p[0].insert(i);
        ind[i]=0;
    }
    while(m--){
        int ti,pi;
        cin >> ti >> pi;
        if(ti==1){ // team solved, remove problem
            int bi = ind[pi];
            p[bi].erase(pi);
            if(p[bi].empty()) p.erase(bi);
            ind.erase(pi);
        }
        else if(ind.find(pi)!=ind.end()){ // other team finished unsolved problem, increase balloons
            int bi=ind[pi]; // current balloon count
            p[bi].erase(pi);
            if(p[bi].empty()) p.erase(bi); // remove empty set
            ind[pi]++;
            p[bi+1].insert(pi);
        }
        if(ind.empty()) cout << "Make noise\n";
        else {
            int min_bi=p.begin()->first,max_bi=p.rbegin()->first;
            cout << *p[max_bi].begin() << " " << *p[min_bi].rbegin() << "\n";
        }
    }
}
