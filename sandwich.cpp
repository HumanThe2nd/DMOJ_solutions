/*
Sandwich
Author: Dan Shan
Date: 2025-08-14
Approach: Deque
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    deque<int> dq;
    for(int i=0;i<n;++i){
        if(s[i]=='1') dq.push_front(i+1);
        else dq.push_back(i+1);
    }
    while(dq.size()){
        cout << dq.front() << "\n";
        dq.pop_front();
    }
}
