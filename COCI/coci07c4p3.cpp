/*
COCI '07 Contest 4 #3 Lektira
Author: Dan Shan
Date: 2025-05-30
brute force each combination
try every 2 split points -> 3 reversed substrings -> new string
return: smallest "new string"
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    vector<string> res;
    for(int i=1;i<n;++i){ // split 1
        for(int j=i+1;j<n;++j){ // split 2
        string s1=s.substr(0,i),s2=s.substr(i,j-i),s3=s.substr(j,n-j);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        reverse(s3.begin(),s3.end());
        s1+=s2+s3;
        res.emplace_back(s1);
        }
    }
    sort(res.begin(),res.end());
    cout << res[0] << "\n";
}
