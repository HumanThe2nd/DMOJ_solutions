/*
Google Code Jam '16 Round 1A Problem B - Rank and File
Author: Dan Shan
Date: 2024-Oct-29
for every letter store its frequency
print odd frequency numbers in increasing order
*/
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		int n,v[2501]={};
		scanf("%d",&n);
		for(int i=0;i<n*(2*n-1);i++){
			int ai;
			scanf("%d",&ai);
			v[ai]++;
		}
		printf("Case #%d: ",ti);
		for(int i=1;i<2501;i++){
			if(v[i]&1) {
				n--;
				printf("%d%s",i,n?" ":"\n");
			}
		}
	}
}
