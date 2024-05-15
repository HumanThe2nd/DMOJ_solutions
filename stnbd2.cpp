// STNBD P2 - Claire Elstein
// By: Dan Shan
// BFS + dp + length tracing
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	vector<int> in(n, 0), out(n, 0);
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		v[a-1].emplace_back(b-1);
		in[b-1]++;
		out[a-1]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in[i] == 0) q.emplace(i);
	}
	long long c=0,dp[n], len[n];
	memset(len, 0, sizeof(len));
	for(int i=0;i<n;i++) if(in[i] == 0) dp[i] = 1;
	else dp[i]=0;
	while(!q.empty()){
		int ni=q.front();
		q.pop();
		for(auto x: v[ni]){
			dp[x] = (dp[x] + dp[ni]) % (int)(1e9+7);
			len[x] = (len[x] + len[ni] + dp[ni]) % (int)(1e9+7);
			if(--in[x] == 0){
				q.emplace(x);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(out[i] == 0){
			c+=len[i]; c%=(int)(1e9+7);
		}
	}
	printf("%lld\n",c);
}
