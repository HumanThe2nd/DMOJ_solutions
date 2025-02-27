/* 
An Animal Contest 2 P2 - Koala Party
Author: Dan Shan
Date: 2024-10-22
special case when n=2, decide whether both can be equal through parity
other cases check if any two numbers cane be combined to match a pre-existing element, if so answer is 3
otherwise answer is 2
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,max=1,min=2e9;
	cin >> n;
	set<int> a;
	for(int i=0;i<n;i++){
		int ai;
		cin >> ai;
		a.insert(ai);
		if(ai>max) max=ai;
		if(ai<min) min=ai;
	}
	if(n==2) return printf("%d\n",!((max-min)&1)+1)*0;
	for(auto x: a){
		for(auto y: a){
			if(x==y) break;
			if((x&1)!=(y&1)) continue; // can't be combined
			if(a.find((x+y)>>1)!=a.end()) return printf("3\n")*0;
		}
	}
	printf("2\n");
}
