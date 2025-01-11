/*
BPC 1 S1 - Homework Questions
Author: Dan Shan
Date: 2025-01-10
Each number collides with every number twice but only with itself once
Finding the values with odd frequencies and dividing them by 2 yeild the original array
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> m;
    int n;
    cin >> n;
    for(int i=0;i<n*n;i++){
        int ai;
        cin >> ai;
        m[ai]++;
    }
    for(auto x: m){
        if(x.second&1) {
            cout << (x.first>>1);
            n--;
            cout << (n?" ":"\n");
        }
    }
}
