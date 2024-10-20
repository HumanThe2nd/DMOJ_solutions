/*
Total Destruction
Author: Dan Shan
Date: 2024-10-20
Observation: max(0,Q-M) capsules have to be connected when broken
we find the distance between each adjacent pair of capsules and connect the smallest distances
Answer given by Q + connections
*/
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}
int a[1000001];
int main() {
	int n,m,q,s=2e9;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<q;i++){
		int ai;
		scanf("%d",&ai);
		a[ai]++;
		if(ai<s) s=ai; // first capsule
	}
	int d[n+1],l=0,r=0,c=0,t=0,b=q-m;
	if(0>b) b=0;
	for(int i=s+1;i<=n;i++){
		if(a[i]){
			d[r]=c;
			c=0; r++;
		}
		else c++;
	}
	qsort(d,r,sizeof(int),cmp);
	while(b--){
		t+=d[l];
		l++;
	}
	printf("%d\n",q+t);
}
