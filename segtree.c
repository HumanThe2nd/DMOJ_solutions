/*
Dynamic Range Minimum Test
Author: Dan Shan
Date: 2024-11-25
Segment tree for minimum update function
*/
#include <stdio.h>
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int MID(int a, int b){
	return a+((b-a)>>1);
}
int MIN(int a,int b){
	return a<b?a:b;
}
int n,m,tree[400001],arr[100001];
int build_util(int ss, int se, int si){
	if(ss==se) { // leaf reached
		tree[si]=arr[ss];
		return arr[ss];
	}
	int mid = MID(ss,se); // binary search remaining intervals
	tree[si] = MIN(build_util(ss,mid,(si<<1)+1),build_util(mid+1,se,(si<<1)+2)); // left and right intervals
	return tree[si];
}
void build(){
	build_util(0,n-1,0);
}
int query_util(int s, int e, int qs, int qe, int index){ // qs and qe: interval boundaries
	if(qs<=s&&qe>=e) return tree[index]; // leaf reached
	if(e<qs||s>qe) return 2e6; // pseudo infinity (out of bounds)
	int mid = MID(s,e);
	return MIN(query_util(s,mid,qs,qe,(index<<1)+1),query_util(mid+1,e,qs,qe,(index<<1)+2)); // find min of both children
}
int query(int s, int e){
	return query_util(0,n-1,s,e,0); // assumes valid boundaries
}
void update_util(int ss, int se, int ind, int val, int si){
	if(ss==se) { // target found
		tree[si]=val; // update target
		return;
	}
	int mid=MID(ss,se);
	if(ind<=mid){ // binary search intervals
		update_util(ss,mid,ind,val,(si<<1)+1);
	} else {
		update_util(mid+1,se,ind,val,(si<<1)+2);
	}
	tree[si]=MIN(tree[(si<<1)+1],tree[(si<<1)+2]); // update new min
}
void update(int s, int e){
	update_util(0,n-1,s,e,0);
}
int main() {
    n=scan(); m=scan();
    for(int i=0;i<n;i++) arr[i]=scan();
    build();
	while(m--){
		char c=getchar_unlocked();
		int s=scan(),e=scan();
		if(c=='M') update(s,e);
		else printf("%d\n",query(s,e));
	}
}
