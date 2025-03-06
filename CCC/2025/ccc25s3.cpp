/*
CCC '25 S3 - Pretty Pens
Author: HumanThe2nd
Date: 2025-03-06
maximal gain: selected_pen_second_max - lowest max of any color
for each color, store a multiset of its prettiness values
create a map of each max and second max to a set of their respective colors
output current sum of max elements + greatest second max - lowest max

color change:
for initial color, remove previous 2 maxes, delete pretiness, then update 2 maxes 
for new color, remove previous 2 maxes, add new prettiness, then update 2 maxes 

'prettiness' change:
delete 2 maxes at selected color, update pretiness value, then 2 update maxes 

Rememeber to update total sum without changes after queries
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<ll, set<ll>> m1,m2; // max: colors, second_max: colors
    ll n,m,q;
    cin >> n >> m >> q;
    ll c[n+1],p[n+1];
    vector<multiset<ll>> a(m+1); // color: values
    for(ll i=1;i<=n;i++) {
        cin >> c[i] >> p[i];
        a[c[i]].insert(p[i]);
    }
    ll sum=0;
    for(ll i=1;i<=m;i++){
        a[i].insert(0); // prevent out of bounds
        ll mi=*a[i].rbegin(); // max at each color
        sum+=mi;
        m1[mi].insert(i);
        mi=*(++a[i].rbegin());
        m2[mi].insert(i);
    }
    ll mx=m2.rbegin()->first,mn=m1.begin()->first;
    cout << sum + max((ll)0,mx-mn) << "\n";
    while(q--){
        ll oi,ai,bi;
        cin >> oi >> ai >> bi;
        ll ci=c[ai],pi=p[ai];
        if(oi==1){ // change color
            ll m1i=*(a[ci].rbegin()),m2i=*(++a[ci].rbegin()); // original color
            sum-=m1i;
            m1[m1i].erase(ci); m2[m2i].erase(ci); // remove current mx and 2nd max
            if(m1[m1i].empty()) m1.erase(m1i);
            if(m2[m2i].empty()) m2.erase(m2i);
            a[ci].erase(a[ci].find(pi));
            m1i=*(a[ci].rbegin()); m2i=*(++a[ci].rbegin());
            m1[m1i].insert(ci); m2[m2i].insert(ci); // update max and 2nd max
            sum+=m1i; // update sum without moves
            // review
            m1i=*(a[bi].rbegin()); m2i=*(++a[bi].rbegin()); // new color
            sum-=m1i;
            m1[m1i].erase(bi); m2[m2i].erase(bi); // remove current mx and 2nd max
            if(m1[m1i].empty()) m1.erase(m1i);
            if(m2[m2i].empty()) m2.erase(m2i);
            a[bi].insert(pi);
            m1i=*(a[bi].rbegin()); m2i=*(++a[bi].rbegin());
            m1[m1i].insert(bi); m2[m2i].insert(bi); // update max and 2nd max
            c[ai]=bi; // update color
            sum+=m1i; // update sum without moves
        }
        else{ // change 'prettiness'
            ll m1i=*(a[ci].rbegin()),m2i=*(++a[ci].rbegin());
            m1[m1i].erase(ci); m2[m2i].erase(ci); // remove current mx and 2nd max
            sum-=m1i;
            if(m1[m1i].empty()) m1.erase(m1i);
            if(m2[m2i].empty()) m2.erase(m2i);
            a[ci].erase(a[ci].find(pi)); // erase old pretty value
            a[ci].insert(bi); // insert new pretty value
            m1i=*(a[ci].rbegin()); m2i=*(++a[ci].rbegin());
            m1[m1i].insert(ci); m2[m2i].insert(ci); // update max and 2nd max
            p[ai]=bi; // update prettiness
            sum+=m1i; // update sum without moves
        }
        mx=m2.rbegin()->first; mn=m1.begin()->first;
        cout << sum + max((ll)0,mx-mn) << "\n";
    }
}
