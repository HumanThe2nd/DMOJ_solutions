/*
COCI '22 Contest 3 #4 Bomboni
Author: Dan Shan
Date: 2024-12-23
2d Grid dp with a third compressioned dimension containing gcd
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	if(b>a){ // make a the larger
		ll temp=b;
		b=a; a=temp;
	}
	while(b){
		ll r=a%b;
		a=b; b=r;	
	}
	return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,mod=998244353;
    cin >> n >> k;
    ll a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> a[i][j];
    }
    if(a[n-1][n-1]<0){ // can't make it to the end
        cout << "0\n";
        return 0;
    }
    vector<vector<unordered_map<ll, ll>>> dp(n, vector<unordered_map<ll, ll>>(n));
    dp[0][0][a[0][0]]=1;
    int f=1,f2=1; // edge clear
    for(int i=1;i<n;i++){
        if(a[i][0]<0) f=0;
        if(a[0][i]<0) f2=0;
        if(f){
            for(auto x: dp[i-1][0]) {
                ll ai=gcd(k,x.first*a[i][0]);
                dp[i][0][ai]=1; // only one path for edges
            }
        }
        if(f2){
            for(auto x: dp[0][i-1]) {
                ll ai=gcd(k,x.first*a[0][i]);
                dp[0][i][ai]=1; // only one path for edges
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[i][j]<1) continue; // skip obstacles
            if(a[i-1][j]>0){ // no pull from obstacles
                for(auto x: dp[i-1][j]){
                    ll ai=gcd(k,x.first*a[i][j]);
                    dp[i][j][ai]=(dp[i][j][ai]+x.second)%mod; // add paths
                }
            }
            if(a[i][j-1]>0){ // no pull from obstacles
                for(auto x: dp[i][j-1]){
                    ll ai=gcd(k,x.first*a[i][j]);
                    dp[i][j][ai]=(dp[i][j][ai]+x.second)%mod;
                }
            }
        }
    }
    cout << dp[n-1][n-1][k] << "\n";
}
