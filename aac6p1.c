/*
An Animal Contest 6 P1 - Workout Routine
Author: Dan Shan
Date: 2024-10-18
Theory: we double k till it is slightly greater than n
we print each pair of numbers of add to k till n/2
if n is odd we print k to fill the missing spot
*/
#include <stdio.h>
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	if(n==1) return printf("%d\n",k)*0; // special case where n=1
	while(k<=n) k*=2;
	for(int i=1;i<=n/2;i++){
		printf("%d %d",i,k-i);
		if(i<n/2) putchar(' ');
	}
	if(n&1) printf(" %d",k);
	putchar('\n');
}
