//============================================================================
// Name        : Mock CCC '18 Contest 1 J3/S1 - A Math Problem
// Author      : Dan Shan
//============================================================================
// Goal: minimum value for given function and domain
// Approach: brute force the ranges for each integer less than 10^4
#include <stdio.h>
int main() {
	int k,p,x;
	scanf("%d %d %d",&k,&p,&x);
	double m = x+k*p;
	for(int i=2;i<10000;i++){
		double res = x*i+(double)k*p/i;
		if(res < m) m = res;
	}
	printf("%0.3lf\n",m);
}
