// CCCHK '15 J4 - Where to build my house?
// Author: Dan Shan
// Date: 2024-09-05
// Approach: Coordinate compression
// Only check coordinates where animal boundaries start and end along with 0 and l
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l,n;
	cin >> l >> n;
	map<int,int> m;
	m[l]=0; // account for last number -> l
	while(n--){
		int a,b;
		cin >> a >> b;
		m[a]++; m[b]--;
	} int lim=m.begin()->first,lst=0,ci=0; // start lim and first coordinate to account for 0 -> first number
	int f=0;
	for(auto x:m){
		ci+=x.second;
		if(ci==0) {
			if(f&&x.first-lst>lim) lim=x.first-lst;
			f=1;
			lst=x.first;
		}
		if(f&&x.first-lst>lim) lim=x.first-lst;
		if(ci!=0) f=0;
	}
	if(l-lst>lim) lim=l-lst;
	printf("%d\n",lim);
}
