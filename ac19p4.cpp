/*
Appleby Contest '19 P4 - Rectangles
Author: Dan Shan
Date: 2024-11-16
add 20000 to coords to account for negatives
for every 2 points we check if the other 2 points exist
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m=0;
    cin >> n;
    vector<set<long long>> g(40006); // compressed array of valid points
    while(n--){
        long long a,b;
        cin >> a >> b;
        g[a+20002].insert(b+20002);
    }
    for(long long i=0;i<40006;i++){
        for(auto x: g[i]){
            for(long long j=40005;j>=i;j--){
                for(auto y: g[j]){
                    if(g[i].find(y)==g[i].end()||g[j].find(x)==g[j].end()) continue; // impossible
                    long long dx=j-i,dy=x-y;
                    if(dy<0) dy=-dy;
                    if(dx*dy>m) m=dx*dy;
                }
            }
        }
    }
    cout << m << "\n";
}
