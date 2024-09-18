// CCCHK '15 S1 - Finding number of pairs
// Author: Dan Shan
// Date: 20240-09-17
// Sort and binary search 
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	long long res=0;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		res+=(upper_bound(a.begin(),a.begin()+i,m-a[i]))-a.begin();
	}
	cout << res%(1000000007) << "\n";
}
