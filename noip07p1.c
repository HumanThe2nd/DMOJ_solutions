// NOIP '07 P1 - Counting Numbers
// Author: Dan Shan
// Coordinate compression
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; 
	cin >> n;
	map<int, int> m;
	while(n--){
		int ai;
		cin >> ai;
		m[ai]++;
	}
	for(auto x: m) cout << x.first << " " << x.second << "\n";
}
