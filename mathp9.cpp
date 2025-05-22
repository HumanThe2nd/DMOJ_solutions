/*
A Math Contest P9 - Buy Some Get Some
Author: Dan Shan
Date: 2025-05-21
Baby-step giant-step algorithm
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod_pow(ll b,int e,ll mod){ // fast exponent with modulus
    ll res=1;
    b%=mod;
    while(e>0) {
        if (e&1)  // If exponent is odd
            res=(res*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return res;
}
ll mod_inv(ll a ,ll p){
    return mod_pow(a,p-2,p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,n,p;
    cin >> a >> n >> p;
    a%=p; n%=p;
    if (n==1){
        cout << "0\n";
        return 0;
    }
    ll m=ceil(sqrt(p+1));
    unordered_map<ll,ll> mp;
    ll ai=1;
    for(int i=0;i<m;++i){ // step 1
        if(mp.find(ai)==mp.end()) mp[ai]=i;
        ai=ai*a%p;
    }
    ll inv = mod_inv(mod_pow(a,m,p),p),y=n;
    for(int i=0;i<m;++i){ // step 1
        if(mp.find(y)!=mp.end()) {
            cout << mp[y]+i*m << "\n";
            return 0;
        }
        y=y*inv%p;
    }
    cout << "DNE\n";
}
