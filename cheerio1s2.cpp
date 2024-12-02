/*
Cheerio Contest 1 S2 - School Expansion
Author: Dan Shan
Date: 2024-12-02
Uses a set to store cost of next room at each floor
keep track of value of next floor through a counter
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,a,b,f=2,c=0;
    cin >> n >> a >> b;
    multiset<long long> s;
    n--; c+=a+b; // first room
    s.insert(a+2*b);
    while(n--){
        auto mi=s.begin();
        long long fi=f*a+b;
        if(*mi>fi){ // add floor
            c+=fi; f++;
            s.insert(fi+b);
            continue;
        } // add room otherwise
        c+=*mi;
        s.erase(mi);
        s.insert(*mi+b);
    }
    cout << c << "\n";
}
