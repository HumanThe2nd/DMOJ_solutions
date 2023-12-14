// Segment Tree Practice 1
// By: Dan Shan
// Template segment tree 
#include <stdio.h>
typedef long long int ll;
ll n,k;
ll tree[2000001];
void build(ll arr[]){
	for(ll i=0;i<n;i++){
		tree[n+i]=arr[i];
	}
	for(ll i=n-1;i>0;--i){
		tree[i]=tree[i<<1] + tree[i<<1|1];
	}
}
void u(ll p, ll v){
	p+=n;
	tree[p]=v;
	for(ll i=p;i>1;i>>=1)
		tree[i>>1] = tree[i] + tree[i^1];
}
ll q(ll l, ll r){
	ll res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)res+=tree[l++];
		if(r&1) res+=tree[--r];
	}
	return res;
}
int main() {
	scanf("%lld %lld",&n,&k);
	ll a[n];
	for(ll i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	build(a);
	for(ll i=0;i<k;i++){
		char s[2]; ll a1,b;
		scanf("%s %lld %lld",s,&a1,&b);a1--;
		if(s[0]=='S')
			printf("%lld\n",q(a1,b));
		else u(a1,b);
	}
}
