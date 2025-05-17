/*
DWITE '12 R1 #3 - Costume Party
Author: Dan Shan
Date: 2025-02-17
Store used strings using a set
print 'names' that contain duplicates or "Spooky" of empty
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int ti=0;ti<5;ti++){
        int n;
        cin >> n;
        unordered_set<string> m;
        vector<string> s;
        for(int i=0;i<n;i++){
            string a,b;
            cin >> a >> b;
            if(m.find(b)==m.end()) m.insert(b);
            else s.emplace_back(a);
        }
        int l=s.size()-1;
        if(l<0){
            cout << "SPOOKY\n";
            continue;
        }
        for(int i=0;i<l;i++){
            cout << s[i] << " ";
        }
        cout << s[l] << "\n";
    }
}
