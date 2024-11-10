/*
Mock CCC '22 2 S1 - Kaguya Wants to Let Ishigami Pass
Author: Dan Shan
Date: 2024-11-10
Recursively find every combination and compare with each student
time complexity: O(n*2^k)
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> s;
int n,k,m=0;
void bf(string si, int d){
    int mi=k;
    for(int i=0;i<n;i++){ // compare
        int c=0;
        for(int j=0;j<k;j++){
            if(s[i][j]==si[j]) c++; 
        }
        if(c<mi) mi=c;
    }
    if(mi>m) m=mi;
    if(d==k) return;
    bf(si,d+1);
    si[d]='F';
    bf(si,d+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    s.resize(n+1);
    for(int i=0;i<n;i++) cin >> s[i];
    string start="T";
    for(int i=1;i<k;i++) start.push_back('T');
    bf(start, 1);
    start[0]='F';
    bf(start, 1);
    cout << m << "\n";
}
