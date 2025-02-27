/*
COCI '16 Contest 6 #3 Turnir
Author: Dan Shan
Date: 2024-12-25
- create an alterantive duplicate array
- assign the exponents of 2 in descending order as levels
- for each number assign the highest exponent of 2 which its sorted index less than or equal to
- reaccess the levels through a map in the original order
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p,n=1;
    cin >> p;
    for(int i=0;i<p;i++) n<<=1;
    vector<int> a(n),a2(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a2[i]=a[i];
    }
    unordered_map<int, int> m;
    sort(a2.begin(),a2.end());
    int ni=1;
    for(int i=1;i<=n;i++){
        if(i>=(ni<<1)){ // increase level
            ni<<=1; p--;
        }
        if(i<n&&a2[i-1]==a2[i]) continue; // use rightmost index
        m[a2[i-1]]=p;
    }
    for(int i=0;i<n-1;i++) cout << m[a[i]] << " ";
    cout << m[a[n-1]] << "\n";
}
