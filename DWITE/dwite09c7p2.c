/*
DWITE '09 R7 #2 - Sum of Primes
Author: Dan Shan
Date: 2024-11-05
Sieve of Eratosthenes
*/
#include <stdio.h>
#include <math.h>
int v[100001];
int main() {
	for(int i=2;i<1001;i++){
		if(v[i]) continue; // already covered
		for(int j=i*i;j<100001;j+=i) v[j]=1;
	}
	for(int ti=5;ti;ti--){
		int n,c=0;
		scanf("%d",&n);
		for(int i=2;i<=n;i++)
			if(!v[i]) c+=i;
		printf("%d\n",c);
	}
}
