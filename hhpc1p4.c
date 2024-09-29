// HHPC1 P4 - Yet Another A+B Problem
// Author: Dan Shan
// Find all factors of c^2 using math in sqrt(c) time
#include <stdio.h>
#include <math.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,c=1,e=0;
		scanf("%d",&n);
		int ni=n;
		while(!(ni&1)){
			ni>>=1; e++;
		}
		c*=2*e+1;
		for(int i=3;i<=sqrt(ni);i+=2){
			e=0;
            while(ni%i==0){
                ni/=i;
                e++;
            }
            c*=2*e+1;
		}
		if(ni>2) c*=3;
		printf("%d\n",c);
	}
}
