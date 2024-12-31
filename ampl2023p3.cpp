/*
Amplitude Hackathon '23 Problem 3 - Dedupe
Author: Dan Shan
Date: 2024-12-31
Map of each event name to expiry time if no occurence or arrival > current expiry
otherwise reject and skip
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, long long> m;
    int n;
    cin >> n;
    while(n--){
        string s;
        long long ai,ei;
        cin >> s >> ai >> ei;
        if(m.find(s)==m.end()||m[s]<ai){
            m[s]=ei;
            cout << "ACCEPTED\n";
        }
        else cout << "REJECTED\n";
    }
}
