/*
TLE '16 Contest 6 (Mock CCC) J3 - Two Kangaroos
Author: Dan Shan
Date: 2024-10-11
parent must consistently hop max distance towards child or hop 1 away from child in both dimensions for max velocity
*/
#include <stdio.h>
#include <math.h>
#define abs(a)((a)<0?-(a):(a))
int main() {
	int x1,y1,k,x2,y2,l;
	scanf("%d%d%d%d%d%d",&x1,&y1,&k,&x2,&y2,&l);
	double x=abs(x1-x2),y=abs(y1-y2);
	int d=k-l;
	if(d<l-1) d=l-1;
	printf("%d\n",(int)ceil((x)/d)+(int)ceil((y)/d));
}
