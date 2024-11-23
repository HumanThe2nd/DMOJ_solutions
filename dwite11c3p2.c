/*
DWITE '11 R3 #2 - Magical Ponds
Author: Dan Shan
Date: 2024-11-23
add every multiple starting from back to 1
divide by the gcd of the sum and largest final product to simplify
Note: I hate this problem
*/
#include <stdio.h>
long long gcd(long long a, long long b){
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
    for(int k=5;k--;){
        int n;
        scanf("%d",&n);
        int m[n],c=1;
        for(int i=0;i<n;i++) scanf("%d",&m[i]);
        for(int i=n-1;i>0;i--){
            c+=m[i];
            m[i-1]*=m[i];
        }
        int g=gcd(c,m[0]);
        printf("%d\n",c/g);
    }
}
