// COCI '16 Contest 5 #2 Pareto
// Author: Dan Shan
// reverse maps
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long t=0,ti=0;
	int n,c=0;
	long double a=0,b=0;
	cin >> n;
	map<int,int> m;
	for(int i=0;i<n;i++){
		int ai;
		cin >> ai;
		m[ai]++;
		t+=ai;
	}
	for(auto it=m.rbegin();it!=m.rend();it++){
		ti+=it->first*it->second;
		c+=it->second;
		if((long double)ti/t-(long double)c/n<b-a) {
			cout << a*100 << "\n" << b*100 << "\n";
			return 0;
		}
		a=(long double)c/n; b=(long double)ti/t;
	}
	cout << a*100 << "\n" << b*100 << "\n";
	return 0;
}
