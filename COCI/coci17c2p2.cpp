// COCI '17 Contest 2 #2 ZigZag
// By: Dan Shan
// String sorting
#include <bits/stdc++.h>
using namespace std;
int c[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    cin >> k >> n;

    vector<vector<string>> v(26);
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        v[s[0] - 'a'].emplace_back(s);
    }
    for (int i = 0; i < 26; i++)sort(v[i].begin(), v[i].end());
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int d = s[0]-'a';
        cout << v[d][c[d]] << "\n";
        if(c[d]<v[d].size()-1)c[d]++;
        else c[d]=0;
    }
}
