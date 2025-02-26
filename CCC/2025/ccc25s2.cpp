/*
CCC '25 S2 - Cryptogram Cracking Club
Author: Dan Shan
Date: 2025-02-19
convert from string to letters with their respective length
modulo total length for 'c'
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    long long c,cur=0,tot=0,l=0;
    vector<char> letters;
    vector<long long> lengths;
    cin >> s >> c;
    char si=s[0];
    for(long long i=1;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z') {
            tot+=cur;
            letters.emplace_back(si);
            lengths.emplace_back(cur);
            if(l) lengths[l]+=lengths[l-1]; // psa
            cur=0; l++;
            si=s[i];
        } 
        else cur=cur*10+s[i]-'0';
    }
    tot+=cur;
    letters.emplace_back(si);
    lengths.emplace_back(cur);
    if(l) lengths[l]+=lengths[l-1],l++; // psa
    c%=tot;
    for(int i=0;i<l;i++){
        if(lengths[i]>c){
            cout << letters[i] << "\n";
            return 0;
        }
    }
    cout << si; // only one character
}
