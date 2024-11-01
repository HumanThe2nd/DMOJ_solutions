/*
Fast Factorial Calculator
Author: Dan Shan
Date: 2024,Nov-01
observation: anything above 33! will be 0 after modulus
for numbers up to 33 compute manually and for anything larger, output zero
*/
#include <stdio.h>
#define m 4294967296
int main() {
	int t;
	long long f=1,a[34];
	scanf("%d",&t); a[0]=1;
	for(int i=1;i<34;i++){
        f*=i;
        f%=m;
		a[i]=f;
    }
	while(t--){
		unsigned long long n;
		scanf("%llu",&n);
		if(n<34) printf("%lld\n",a[n]);
		else printf("0\n");
	}
}
