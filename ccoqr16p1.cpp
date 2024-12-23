/*
CCOQR '16 - Stupendous Bowties
Author: Dan Shan
Date: 2024-12-23
2d Coordinate compression storing x and y indexes mapped to their respected coords
binary search number of combinations above and below for each dimension
double the final answer as the bowties can all be rotated 90 degrees to make another
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,c=0;
    cin >> n;
    map<ll, vector<ll>> x,y;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        x[a].emplace_back(b);
        y[b].emplace_back(a);
    }
    for(auto &xi:x) {
        sort(xi.second.begin(),xi.second.end());
    }
    for (auto &yi:y) {
        sort(yi.second.begin(),yi.second.end());
    }
    for (auto &xi:x) {
        long long f=xi.first;
        auto &s=xi.second;
        for (auto yi:s) {
            // Use lower_bound to get index
            long long mi = lower_bound(s.begin(),s.end(),yi)-s.begin(); // below x coord
            mi*=(s.size()-mi-1); // multiply by larger x coords
            // Use lower_bound for y[yi]
            auto &col=y[yi];
            long long m2=lower_bound(col.begin(),col.end(),f)-col.begin(); // below y coord
            m2*=(col.size()-m2-1); // multiply by larger y coords
            c+=mi*m2;
        }
    }
    cout << (c<<1) << "\n";
}
