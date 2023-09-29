//============================================================================
// Name        : DMOPC '21 Contest 2 P1 - Bosses
// Author      : Dan Shan
//============================================================================
// Goal: find minimum time to complete given time for temp and perm increase
// Approach: Sort in decending order and check each combination
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	ll n,h,p,m=LLONG_MAX,c=0;
	scanf("%lld %lld %lld",&n,&h,&p);
	vector<ll> b;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		b.push_back(in);
	}
	b.push_back(0);
	n++;
	sort(b.begin(),b.end(),greater<>());
	for(int i=0;i<n-1;i++){
		ll sum = h*b[i]+c*p;
		m = min(m,sum);
		c+=(b[i]-b[i+1])*(i+1);
	}
	m = min(m,c*p);
	printf("%lld\n",m);
}
