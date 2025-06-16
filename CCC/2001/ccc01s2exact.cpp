/*
CCC '01 S2 - Spirals (Exact Version)
Author: Dan Shan
Date: 2025-06-16

Ordering:
2d deque -> simple & efficient updates
Pattern modulo 4: left(0),down(1), right(2), up(3)
lengths: 1,1,2,2,3,3,4,4, etc

** I believe this part was optional for the CCC
Presentation:
1. Use longest column lengths to determine dimensions
2. Hard-Coded every special case (There's probably better methods?)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int x,y,p=1;
        cin >> x >> y;
        deque<deque<int>> dq={{x++}};
        while(x<=y){
            int si=dq.size();
            if(p%4==0){ // left
                for(int i=0;i<(p>>1)&&x<=y;++i){
                    dq.front().emplace_front(x++);
                }
            }
            else if(p%4==1){ // down
                for(int i=1;i<=(p>>1)&&x<=y;++i){
                    dq[i].emplace_front(x++);
                }
                if(x<=y) dq.emplace_back(deque<int>{x++});
            }
            else if(p%4==2){ // right
                for(int i=0;i<(p>>1)&&x<=y;++i){
                    dq.back().emplace_back(x++);
                }
            }
            else{ // up
                for(int i=2;i<=dq.size()&&x<=y;++i){
                    dq[dq.size()-i].emplace_back(x++);
                }
                if(x<=y) dq.emplace_front(deque<int>{x++});
            } ++p; // next
        }
        /* Non-Exact Output
        for(auto x: dq){
            for(auto y: x){
                cout << y << " ";
            }
            cout << "\n";
        }*/
        int n=dq.size(),m=max(dq.front().size(),dq.back().size());
        vector<vector<string>> res(n);
        for(int i=0;i<n;++i){
            int mi=dq[i].size();
            for(int j=0;j<mi;++j){
                res[i].push_back(to_string(dq[i][j]));
            }
        }
        if(res.size()>1&&stoi(res[1][0])<stoi(res[0][0])){ // leading whitespace 1
            while(res[0].size()<m) res[0].insert(res[0].begin(),"z");
            if(res[0].size()>res[1].size()) for(int j=1;j<n;++j) res[j].insert(res[j].begin(),"z");
        }
        for(int i=2;i<n;++i) if(res[i][0]!=""&&res[i-1][0]!=""&&res[i][0]!="z"&&res[i-1][0]!="z"&&stoi(res[i][0])<stoi(res[i-1][0])){ // leading whitespaces
            for(int j=i;j<n;++j) {
                res[j].insert(res[j].begin(),"z");
            }
        }
        
        for(int i=0;i<n;++i){ // fix trailing whitespaces
            while(res[i].size()<m) res[i].emplace_back("z");
        }
        vector<int> col(m+1,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) {
                col[j]=max(col[j],(int)res[i][j].size());
            }
        }
        for(int i=0;i<n;++i){
            if(res[i][0]=="z") res[i][0]=" ";
            while(res[i][0].size()<col[0]) res[i][0]=" "+res[i][0];
            cout << res[i][0];
            for(int j=1;j<m;++j){
                if(res[i][j]=="z") res[i][j]=" ";
                while(res[i][j].size()<col[j]) res[i][j]=" "+res[i][j];
                cout << " " << res[i][j];
            }
            cout << "\n";
        }
        if(t) cout << "\n";
    }
}
