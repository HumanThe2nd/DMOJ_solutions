/*
Triple-Ended Queue
Author: Dan Shan
Date: 2025-06-16
1. Use 2 deques for the first n/2 and remaining elements respectively
2. Middle: first element of the right array
3. Ensure both arrays are always balanced as specificed
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n;
    deque<int> l,r;
    for(int i=0;i<(n>>1);++i){
        int ai;
        cin >> ai;
        l.emplace_back(ai);
    }
    for(int i=(n>>1);i<n;++i){
        int ai;
        cin >> ai;
        r.emplace_back(ai);
    }
    cin >> q;
    while(q--){
        string ai,bi;
        cin >> ai >> bi;
        if(ai[0]=='p'){ // pop
            if(bi[0]=='l') { // left
                if(l.size()) cout << l.front() << "\n",l.pop_front();
                else cout << r.back() << "\n",r.pop_back();
            }
            else if(bi[0]=='m') cout << r.front() << "\n",r.pop_front(); // mid
            else cout << r.back() << "\n",r.pop_back();
        }
        else{ // append
            int ci;
            cin >> ci;
            if(bi[0]=='l') l.emplace_front(ci); // left
            else if(bi[0]=='m') {
                if(r.size()>l.size()){
                    l.emplace_back(r.front());
                    r.pop_front();
                    r.emplace_front(ci);
                }
                else r.emplace_front(ci); // mid
            }
            else r.emplace_back(ci); // right
        }
        if(r.size()>l.size()+1){ // balance 
            l.emplace_back(r.front());
            r.pop_front();
        }
        else if(r.size()<l.size()){ // balance
            r.emplace_front(l.back());
            l.pop_back();
        }
    }
}
