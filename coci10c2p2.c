// COCI '10 Contest 2 #2 Napor
// By: Dan Shan
// Comparitive sorting strings 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s,n;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(s[i]>'9'||s[i]<'0'){
                if(n.length()>0) v.emplace_back(n);
                n = "";
            }
            else n+=s[i];
        }
        if(n.length()>0) v.emplace_back(n);
    }
    for(auto &x: v){
        while(x.size()>1 && x[0]=='0') x.erase(x.begin());
    }
    sort(v.begin(),v.end(),[&](string a, string b){return a.length()<b.length()||(a.length()==b.length()&&a<b);});
    for(auto x: v) cout << x << "\n";
}
