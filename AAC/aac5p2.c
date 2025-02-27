/*
An Animal Contest 5 P2 - Permutations & Products
Author: Dan Shan
Date: 2024-10-19
if a1 = 1 then we print 1 followed by the array
otherwise we could use the minimum to determine a1
when a1 > 1, minimum = a1*1 = a1
dividing all remaining numbers by a1 will give their real value
inputs may overflow 32 bit integers
*/
#include <stdio.h>
int main() {
	long long n;
	scanf("%lld",&n);
	long long a[n],m1=2e9,m2=1;
	for(int i=1;i<n;i++){
		printf("? %d %d\n",1,i+1);
		fflush(stdout);
		scanf("%lld",&a[i]);
		if(a[i]<m1) m1=a[i];
		if(a[i]>m2) m2=a[i];
	}
	if(m2==n){ // special case  a1=1
		printf("! 1 ");
		for(int i=1;i<n-1;i++) printf("%lld ",a[i]);
		printf("%lld\n",a[n-1]);
		return 0;
	}
	printf("! %lld ",m1);
	for(int i=1;i<n-1;i++) printf("%lld ",a[i]/m1);
	printf("%lld\n",a[n-1]/m1);
}
