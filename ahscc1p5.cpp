/*
Arcadia Computing Contest 1 P5 - Hacking Grades
Author: Dan Shan
Date: 2024-12-31
Map marginal increase as a decimal to its respective fraction
take the largest marginal increase k times while updating the map
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<double, vector<long long>> mp; // map marginal increase to numerator & denominator
    long long n,k,m=1e9+1; // pseudoinfinity
    cin >> n >> k;
    long long a[n];
    double c=0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        long long di;
        cin >> di;
        c+=(double)a[i]/di;
        double d=((double)a[i]+1)/(di+1)-(double)a[i]/di;
        mp[d].emplace_back(di*m+a[i]);
    }
    while(k--){
        double k=mp.rbegin()->first;
        long long cur=mp[k].back();
        mp[k].pop_back();
        if(mp[k].empty()) mp.erase(k);
        long long ni=cur%m,di=cur/m; // current fraction
        ni++; di++;
        double d=(double)(ni+1)/(di+1)-(double)ni/di;
        c+=k;
        mp[d].emplace_back(cur+m+1); // next margin and respective fraction
    }
    printf("%lf\n",100*c/n);
}
