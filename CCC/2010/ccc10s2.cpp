// CCC '10 S2 - Huffman Encoding
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int k;
    cin >> k;
    unordered_map<string, string> m;
    for(int i=0;i<k;i++){
        string s,v;
        cin >> s >> v;
        m[v]=s;
    }
    string s,t;
    cin >> s;
    for(int i=0;i<s.length();i++){
        t.push_back(s[i]);
        if(m.find(t)!=m.end()){
            cout << m[t];
            t.clear();
        }
    }
    cout << "\n";
}
