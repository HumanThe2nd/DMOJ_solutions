/*
DMOPC '14 Exam Time P2 - Physics Duel
Author: Dan Shan
Date: 2024-Nov-14
*/
#include <stdio.h>
#include <math.h>
int main() {
	int n;
	double h=0,p=3.14159265359/180;
	scanf("%d",&n);
	while(n--){
		double x,s,t;
		scanf("%lf %lf %lf",&x,&s,&t);
		h+=x*t*sin(s*p);
	}
	printf("%0.0lf\n",sqrt(2*9.8*h));
}
