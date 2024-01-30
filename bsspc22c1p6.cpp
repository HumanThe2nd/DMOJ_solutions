// BSSPC '22 P6 - Permutations & Primogems
// By: Dan Shan
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
int main() {
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int n,m;
cin >> n >> m;
ll dp[m+1];
dp[0]=0;
for(int i=1;i<=m;i++)dp[i]=1e17;
vector<pi> v(n);
for(int i=0;i<n;i++){
	cin >> v[i].first >> v[i].second;
} // descending
sort(v.begin(),v.end(),[&](pi a, pi b){return a.first>b.first;});
for(int i=0;i<n;i++){
	for(int j=m;j>0;j--){
		ll cur = dp[j-1]+v[i].first*(j-1)+v[i].second;
		if(cur<dp[j]) dp[j]=cur;

	}
}
cout << dp[m] << "\n";
}
