/*
Mock CCC '18 Contest 3 J2 - A Palindrome Problem
Autor: Dan Shan
Date: 2025-09-10
Brute force every split and check if 2 substrings are palindromes
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if(s.size() < 2) return !puts("NO");
    for(int i=1; i < s.size(); ++i){
        int f = 1;
        string si = s.substr(0,i), sf = s.substr(i);
        for(int j=0; j < si.size()/2; ++j) if(si[j] != si[si.size() - j - 1]) f = 0;
        for(int j=0; j < sf.size()/2; ++j) if(sf[j] != sf[sf.size() - j - 1]) f = 0;
        if(f) return !puts("YES");
    }
    puts("NO");
}
