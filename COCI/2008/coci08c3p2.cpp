/*
COCI '08 Contest 3 #2 Kemija
Author: Dan Shan
Date: 2025-06-24
Skip 2 chaarcters when encountering a vowel
Time Complexity: O(N)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,res;
    getline(cin,s);
    char v[]={'a','i','e','u','o'};
    for(int i=0;i<s.size();++i){
        res.push_back(s[i]);
        int f=0;
        for(int j=0;j<5;++j){
            if(s[i]!=v[j]) continue;
            f=1; break;
        }
        if(f) i+=2;
    }
    cout << res << "\n";
}
