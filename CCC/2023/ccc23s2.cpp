//============================================================================
// Name        : CCC '23 S2 - Symmetric Mountains
// Author      : HumanThe2nd
// Date        : 2023-07-13
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> m,res;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		m.push_back(in);
		res.push_back(1000000);
	}
	res[0]=0;
	for(int i=0;i<n-1;i++){
		int r=i+1,l=i,a=0;
		while(l>=0&&r<n){
			int s=r-l;
			a+=abs(m[l]-m[r]);
			res[s]=min(res[s],a);
			r++; l--;
		}
	}
	for(int i=1;i<n-1;i++){
		int l=i-1,r=i+1,a=0;
		while(l>=0&&r<n){
			int s = r-l;
			a+=abs(m[l]-m[r]);
			res[s]=min(res[s],a);
			r++; l--;
		}
	}
	for(int i=0;i<n-1;i++)printf("%d ",res[i]);
	printf("%d\n",res.back());
}
