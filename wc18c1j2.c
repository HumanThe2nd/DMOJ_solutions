/*
WC '18 Contest 1 J2 - Making the Cut
Author: Dan Shan
Date: 2025-08-10
Compare each string with the target
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string target,current,res="N\n";
    cin >> target;
    for(int i=0;i<5;++i){
        cin >> current;
        if(target==current) {
            res="Y\n"; break;
        }
    }
    cout << res;
}
