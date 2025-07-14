/*
CCO '01 P4 - Breaking Level (Standard I/O)
Author: Dan Shan
Date: 2025-07-14
Egg Drop problem:
1st egg: Start from d and increase by d-i for each guess 'i' until broken
2nd egg: Try each value starting from the last safe range until broken
H: 2nd break-1 (or x+d if break never occurs)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d,ai=0,x=0;
    cout << "GetN\n" << flush;
    cin >> n;
    d=ceil((-1+sqrt(1+8*n))/2);
    while(!ai){ // 1st egg
        cout << "Drop " << x+d << "\n" << flush;
        cin >> ai;
        if(!ai) x+=d--;
    }
    for(int i=1;i<d;++i){
        cout << "Drop " << x+i << "\n" << flush;
        cin >> ai;
        if(ai){
            cout << "Decide " << x+i << "\n";
            return 0;
        }
    }
    cout << "Decide " << x+d << "\n";
}
