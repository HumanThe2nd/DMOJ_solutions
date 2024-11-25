/*
Arcadia Computing Contest 1 P1 - Test Anxiety
Author: Dan Shan
Date: 2024-11-24
a*b+c>=80*(b+1)
c>=80*(b+1)-a*b
plugging in a and b we get the minimum for c
*/
#include <stdio.h>
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	int c=80*(b+1)-a*b;
	if(c>100) printf("-1\n");
	else if(c<1) printf("0\n");
	else printf("%d\n",c);
}
