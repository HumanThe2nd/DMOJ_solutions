/*
COCI '09 Contest 5 #1 Sok
Author: Dan Shan
Date: 2024-11-25
find ratios, remove minimum from all, return ratios to original forms
*/
#include <stdio.h>
int main() {
	double a,b,c;
	int d,e,f;
	scanf("%lf %lf %lf %d %d %d",&a,&b,&c,&d,&e,&f);
	a/=d; b/=e; c/=f;
	double m=a;
	if(b<m) m=b;
	if(c<m) m=c;
	a-=m; b-=m; c-=m;
	a*=d; b*=e; c*=f;
	printf("%0.4lf %0.4lf %0.4lf",a,b,c);
}
