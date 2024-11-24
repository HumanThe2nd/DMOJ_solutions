// CCC '97 S4 - Dynamic Dictionary Coding
// By: Dan Shan
// Paragraph inputting
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for(int t=0;t<n;t++){
        int c=1,nl=0,l=0,r=0;
        char ch,a[1000];
        string s;
        unordered_map<string, int> d;
        while(cin.get(ch)){
            if(ch=='\n')nl++;
            else nl=0;
            s+=ch;
            if(ch=='\n'||ch==' '){
                a[r]=ch; r++;
            }
            if(nl>1) break;
        }
        istringstream is(s);
        string w;
        while(is>>w){ 
            if(d.find(w)==d.end()){
                d[w]=c; c++;
                cout << w << a[l];
            } 
            else cout << d[w] << a[l];
            l++;
    }
    if(t<n-1) cout<<"\n";
    }
    cout << "\n";
}
