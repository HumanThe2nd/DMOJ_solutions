#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int c = 0;
    for(int i = 0; i < s.size(); ++i){
        c += (s[i] != ' ');
    }
    cout << c << "\n";
}
