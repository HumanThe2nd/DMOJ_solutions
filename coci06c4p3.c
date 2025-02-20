/*
COCI '06 Contest 4 #3 Prsteni
Author: Dan Shan
Date: 2025-02-20
First element: numerator
Use every other element as a denominator
divide both numbers by their gcd to simplify
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
long long gcd(long long a, long long b){ // template gcd
	if(b>a){ // make a the larger
		long long temp=b;
		b=a; a=temp;
	}
	while(b){
		long long r=a%b;
		a=b; b=r;	
	}
	return a;
}
int main() {
    int n,a;
    scanf("%d %d",&n,&a);
    for(int i=1;i<n;i++){
        int b;
        scanf("%d",&b);
        int g=gcd(a,b);
        printf("%d/%d\n",a/g,b/g);
    } 
}
