// CCC '08 S2 - Pennies in the Ring
// Author: Dan Shan
// Date: 2024-09-18
// analyze increments and notice a pattern
#include <stdio.h>
#include <math.h>
int main() {
    while(1){
		int n,c=0;
		scanf("%d",&n);
		if(!n) break;
		for(int i=1;i<=n;i++) c+=sqrt(n*n-(double)i*i)+1;
		c=c*4+1;
		printf("%d\n",c);
	}
}
