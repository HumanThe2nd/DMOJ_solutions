/*
DMOPC '14 Contest 6 P1 - Finding Bessarion
Author: Dan Shan
Date: 2025-06-22
Check every 3 adjacent strings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> a(n);
    for(int i=0;i<n;++i) getline(cin,a[i]);
    for(int i=2;i<n;++i){
        if(a[i-1]!="Bessarion") continue;
        if((a[i-2]=="Bayview"&&a[i]=="Leslie")||(a[i-2]=="Leslie"&&a[i]=="Bayview")) return !puts("Y");
    }
    puts("N");
}
