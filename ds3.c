/*
Segment Tree Test
Author: Dan Shan
Date: 2024-12-09
Theory: 3 segment trees storing min, gcd and gcd frquency
minimum element, GCD of range, frequency of GCD
All GCD start as themselves and can only grow smaller
If either branch is equal to the gcd add it's frequency
*/
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int gcd(int a,int b){
	if(b>a){ // make a the larger
		int temp=b;
		b=a; a=temp;
	}
	while(b){
		int r=a%b;
		a=b; b=r;	
	}
	return a;
}
int MID(int a, int b){
	return a+((b-a)>>1);
}
int MIN(int a,int b){
	return a<b?a:b;
}
int n,m,tree[400001],t2[400001],t3[400001],arr[100001];
int build_util(int ss, int se, int si){
	if(ss==se) { // leaf reached
		tree[si]=arr[ss]; // Min starts as itself
		t2[si]=arr[ss]; // GCD starts at itself
		t3[si]=1; // frequency starts at 1
		return arr[ss];
	}
	int mid = MID(ss,se);
	tree[si] = MIN(build_util(ss,mid,(si<<1)+1),build_util(mid+1,se,(si<<1)+2)); // left and right intervals
	t2[si]=gcd(t2[(si<<1)+1],t2[(si<<1)+2]);
	t3[si]=0;
	if(t2[(si<<1)+1]==t2[si]) t3[si]+=t3[(si<<1)+1];
	if(t2[(si<<1)+2]==t2[si]) t3[si]+=t3[(si<<1)+2];
	return tree[si];
}
void build(){
	build_util(0,n-1,0);
}
int query_util(int s, int e, int qs, int qe, int index){ // qs and qe: interval boundaries
	if(qs<=s&&qe>=e) return tree[index]; // leaf reached
	if(e<qs||s>qe) return 2e9; // pseudo infinity (out of bounds)
	int mid = MID(s,e);
	return MIN(query_util(s,mid,qs,qe,(index<<1)+1),query_util(mid+1,e,qs,qe,(index<<1)+2)); // find min of both children
}
int query(int s, int e){
	return query_util(0,n-1,s,e,0); // assumes valid boundaries
}
int q2_util(int s, int e, int qs, int qe, int index){ // qs and qe: interval boundaries
	if(qs<=s&&qe>=e) return t2[index]; // leaf reached
	if(e<qs||s>qe) return 0; // pseudo infinity (out of bounds)
	int mid = MID(s,e);
	return gcd(q2_util(s,mid,qs,qe,(index<<1)+1),q2_util(mid+1,e,qs,qe,(index<<1)+2)); // find min of both children
}
int q2(int s, int e){
	return q2_util(0,n-1,s,e,0); // assumes valid boundaries
}
int q3_util(int s, int e, int qs, int qe, int g, int index){// qs and qe: interval boundaries
	if(qs<=s&&qe>=e) return t2[index]==g?t3[index]:0; // leaf reached
	if(e<qs||s>qe) return 0; // invalid
	int mid = MID(s,e);
	return q3_util(s,mid,qs,qe,g,(index<<1)+1)+q3_util(mid+1,e,qs,qe,g,(index<<1)+2);
}
int q3(int s, int e){
	int g=q2(s,e); // GCD of current range
	return q3_util(0,n-1,s,e,g,0); // assumes valid boundaries
}
void update_util(int ss, int se, int ind, int val, int si){
	if(ss==se) { // target found
		tree[si]=val; // update target
		t2[si]=val;
		t3[si]=1;
		return;
	}
	int mid=MID(ss,se);
	if(ind<=mid){ // binary search intervals
		update_util(ss,mid,ind,val,(si<<1)+1);
	} else {
		update_util(mid+1,se,ind,val,(si<<1)+2);
	}
	tree[si]=MIN(tree[(si<<1)+1],tree[(si<<1)+2]); // update new min
	t2[si]=gcd(t2[(si<<1)+1],t2[(si<<1)+2]);
	t3[si]=0;
	if(t2[(si<<1)+1]==t2[si]) t3[si]+=t3[(si<<1)+1];
	if(t2[(si<<1)+2]==t2[si]) t3[si]+=t3[(si<<1)+2];
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
		int s=scan(),e=scan(); s--;
		if(c=='C') update(s,e);
		else if(c=='M') printf("%d\n",query(s,e-1));
		else if(c=='G') printf("%d\n",q2(s,e-1));
		else printf("%d\n",q3(s,e-1));
	}
}
