/*
COCI '09 Contest 3 #1 Filip
Author: Dan Shan
Date: 2024-11-09
reverse numbers and find max
*/
#include <stdio.h>
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	int ai=a%10,bi=b%10;
	ai*=10; bi*=10;
	ai+=(a/10)%10;
	bi+=(b/10)%10;
	ai*=10; bi*=10;
	ai+=a/100; bi+=b/100;
	if(ai>bi) printf("%d\n",ai);
	else printf("%d\n",bi);
}
