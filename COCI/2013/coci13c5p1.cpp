/*
COCI '13 Contest 5 #1 Lozinka
Author: Dan Shan
Date: 2025-05-07
Store every string and check for its reverse
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<string> si;
    while(n--){
        string s;
        cin >> s;
        if(!(s.size()&1)) continue;
        si.push_back(s);
        reverse(s.begin(),s.end());
        for(string x: si){
            int sz=x.size();
            if(sz!=s.size()) continue;
            if(x==s){
                cout << sz << " " << s[sz/2] << "\n";
                return 0;
            }
        }
    }
}
