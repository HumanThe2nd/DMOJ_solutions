/*
Segment Tree Practice 2
Author: Dan Shan
Date: 2024-11-29
Dynamic minimum range queries with minimum index stored as well
*/
#include <stdio.h>
typedef long long ll;
ll scan() {
    ll num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
ll MID(ll a, ll b){
	return a+((b-a)>>1);
}
ll n,m,tree[800001],arr[200001],mod=2e9;
ll build_util(ll ss, ll se, ll si){
	if(ss==se) { // leaf reached
		tree[si]=arr[ss]+mod*ss;
		return tree[si];
	}
	ll mid = MID(ss,se); // binary search remaining intervals
	ll s1=build_util(ss,mid,(si<<1)+1),s2=build_util(mid+1,se,(si<<1)+2);
	if(s1%mod>s2%mod) s1=s2; // minimum value
	tree[si] = s1; // left and right intervals
	return tree[si];
}
void build(){
	build_util(0,n-1,0);
}
ll query_util(ll s, ll e, ll qs, ll qe, ll index){ // qs and qe: interval boundaries
	if(qs<=s&&qe>=e) return tree[index]; // leaf reached
	if(e<qs||s>qe) return mod-1; // pseudo infinity (out of bounds)
	ll mid = MID(s,e);
	ll s1=query_util(s,mid,qs,qe,(index<<1)+1),s2=query_util(mid+1,e,qs,qe,(index<<1)+2);
	if(s1%mod>s2%mod) s1=s2; // minimum
	return s1; // find min of both children
}
ll query(ll s, ll e){
	return query_util(0,n-1,s,e,0); // assumes valid boundaries
}
void update_util(ll ss, ll se, ll ind, ll val, ll si){
	if(ss==se) { // target found
		tree[si]=val+mod*ss; // update target
		return;
	}
	ll mid=MID(ss,se);
	if(ind<=mid){ // binary search intervals
		update_util(ss,mid,ind,val,(si<<1)+1);
	} else {
		update_util(mid+1,se,ind,val,(si<<1)+2);
	}
	ll s1=tree[(si<<1)+1],s2=tree[(si<<1)+2];
	if(s1%mod>s2%mod) s1=s2; // minimum
	tree[si]=s1; // update new min
}
void update(ll s, ll e){
	update_util(0,n-1,s,e,0);
}
int main() {
    n=scan(); m=scan();
    for(int i=0;i<n;i++) arr[i]=scan();
    build();
	while(m--){
		char c=getchar_unlocked();
		ll s=scan(),e=scan();
		s--;
		if(c=='U') update(s,e);
		else {
			e--;
			ll qi=query(s,e);
			printf("%lld %lld\n",qi%mod,qi/mod+1);
		}
	}
}
