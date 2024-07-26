// Amplitude Hackathon Summer '24 Problem 2 - Feature Requests
// Author: Dan Shan
// Mapping and custom sorting
#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, string>;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<string, int> m;
	while(n--){
		int a;
		cin >> a;
		while(a--){
			string s;
			cin >> s;
			m[s]++;
		}
	}
	vector<pi> v;
	for(auto x:m){
		v.emplace_back(x.second,x.first);
	}
	stable_sort(v.begin(),v.end(),[&](pi a, pi b){return a.first>b.first;});
	for(auto x: v){
		cout << x.second << " " << x.first << "\n";
	}
}
