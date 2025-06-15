/*
DMOPC '15 Contest 4 P1 - Dictionary
Author: Dan Shan
Date: 2025-06-14
Sort strings lexicographically
When Outputting, follow with ", " if it starts with same letter as next
                  otherwise: "\n"
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;++i) cin >> s[i];
    sort(s.begin(),s.end());
    for(int i=0;i<n-1;++i){
        cout << s[i];
        cout << ((s[i][0]==s[i+1][0])?", ":"\n");
    }
    cout << s.back() << "\n";
}
