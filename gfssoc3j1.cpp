/*
GFSSOC '15 Winter J1 - Festive Fardin
Author: Dan Shan
Date: 2025-07-05
1. input 2 lines as strings
2. check if both are valid
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    if((a=="green"||a=="red"||a=="white")&&(b=="green"||b=="red"||b=="white")) cout << "Jingle Bells\n";
    else cout << "Boring...\n";
}
