//============================================================================
// Name        : CCC '18 S1 - Voronoi Villages
// Author      : Dan Shan
//============================================================================
// Goal: find point closest to 2 other points when sorted
// Approach: sort all inputs and iterate over the 2nd to 2nd last
//			 updating the new minimum after each point
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	double m = INT_MAX;
	int n;
	scanf("%d",&n);
	vector<int> v;
	n--;
	for(int i=0;i<=n;i++){
		int in;
		scanf("%d",&in);
		v.push_back(in);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<n;i++){
		if((double)(v[i+1]-v[i-1])/2<m)m= (double)(v[i+1]-v[i-1])/2;
	}
	printf("%.1f",m);
}
