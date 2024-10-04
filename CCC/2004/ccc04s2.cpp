// CCC '04 S2 - TopYodeller
// Author: Dan Shan
// 2024-09-19
// update maximums each iteration and store sum of columns
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n),l(n);
	for(int i=0;i<n;i++) {
		a[i]=0; l[i]=0;
	}
	while(k--){
		map<int, vector<int>> m;
		for(int i=0;i<n;i++) {
			int ai;
			cin >> ai;
			a[i]+=ai;
			m[a[i]].emplace_back(i);
		}
		int i=1;
		for(auto x=m.rbegin();x!=m.rend();x++){
			for(auto s: x->second){
				if(i>l[s]) l[s]=i;
			}
			i++;
		}
	}
	int max=-1e9;
	queue<int> y;
	for(int i=0;i<n;i++){
		if(a[i]>max) max=a[i];
	} 
	for(int i=0;i<n;i++) if(a[i]==max) y.emplace(i);
	while(!y.empty()){
		int yi=y.front(); y.pop();
		cout << "Yodeller " << yi+1 << " is the TopYodeller: score " << max << ", worst rank " << l[yi] << "\n";
	}
}
