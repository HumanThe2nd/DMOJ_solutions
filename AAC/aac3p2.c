/*
An Animal Contest 3 P2 - Monkey Potato
Author: Dan Shan
Date: 2024-11-06
Smallest positive number and start and end
Fill space between with Smallest non-negative number
Special Case: no positive numbers: return -1
*/
#include <stdio.h>
int main() {
	int k,d,z=0,m=10;
	scanf("%d %d",&k,&d);
	while(d--){
		int ai;
		scanf("%d",&ai);
		if(!ai) z=1;
		else if(ai<m) m=ai;
	}
	if(m==10) return printf("-1\n")*0;
	printf("%d",m);
	for(int i=2;i<k;i++){
		if(z) putchar('0');
		else printf("%d",m);
	}
	if(k>1) printf("%d\n",m);
	else putchar('\n');
}
