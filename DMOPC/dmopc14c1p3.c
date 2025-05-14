// DMOPC '14 Contest 1 P3 - New Students
// Author: Dan Shan
// Date: 2024-10-12
// calculate average of running sum
#include <stdio.h>
int main() {
	int n,n2;
	double c=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double ai;
		scanf("%lf",&ai);
		c+=ai;
	}
	scanf("%d",&n2);
	while(n2--){
		double ai;
		scanf("%lf",&ai);
		n++; c+=ai;
		printf("%lf\n",c/n);
	}
}
