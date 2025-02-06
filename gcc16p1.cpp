/*
GCC '16 P1 - Watching Anime
Author: Dan Shan
Date: 2025-02-05
map each coordinate to animes (1 each) and commitments (1e6 each)
iterate the coordinates in relative order,
if running sum is nonzero and less than 1e6, add time elapsed from last timestamp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<ll, ll> m;
    ll n,a,b,mod=1e6,l=1,c=0;
    cin >> n >> a >> b;
    m[n+1]=0;
    while(a--){
        ll ai,bi;
        cin >> ai >> bi;
        m[ai]++; m[bi+1]--;
    }
    while(b--){
        ll ai,bi;
        cin >> ai >> bi;
        m[ai]+=mod;
        m[bi+1]-=mod;
    }
    ll xi=0;
    for(auto x: m){
        if(xi&&xi<mod) c+=x.first-l;
        xi+=x.second;
        l=x.first;
    }
    cout << c << "\n";
}
