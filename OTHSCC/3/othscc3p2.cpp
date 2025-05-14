/*
OTHS Coding Competition 3 P2 - Together Forever
Author: Dan Shan
Date: 2025-02-07
store Shirogane's schedule and the indexes that his courses appear
store Shinomiya's array
for each index that differs between the arrays,
In Shirogane's schedule, swap it with an index of Shinomiya's respective course
Prune any index thst occurs before the current
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n),x,y;
    vector<vector<int>> f(n+1); // value: indexes
    for(int i=0;i<n;i++){
        cin >> a[i];
        f[a[i]].emplace_back(i);
    }
    for(int i=0;i<n;i++){
        int ai;
        cin >> ai;
        if(ai==a[i]) continue; // already matches
        int aii=f[ai].back();
        while(aii<i){
            f[ai].pop_back();
            aii=f[ai].back();
        }
        x.emplace_back(i+1); y.emplace_back(aii+1);
        f[a[i]].emplace_back(f[ai].back());
        a[f[ai].back()]=a[i];
        a[i]=ai;
        f[ai].pop_back();
    }
    int s=x.size();
    cout << s << "\n";
    for(int i=0;i<s;i++){
        cout << x[i] << " " << y[i] << "\n";
    }
}
