/*
DMOPC '17 Contest 5 P3 - Mimi and Primes
Author: Dan Shan
Date: 2024-11-04
Observation: prime GCD is largest prime factor of the real GCD
Euclidian algorithm for GCD
Prime factorization of GCD
*/
#include <stdio.h>
#include <math.h>
long long gcd(long long a, long long b){ // Euclidation algorithm
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
long long pgcd(long long n){
	long long m=-1;
	while(!(n&1)){
		m=2;
		n>>=1;
	}
	for(int i=3;i<=sqrt(n);i+=2){
		while(n%i==0){
			m=i;
			n/=i;
		}
	}
	if(n>m) m=n; // remainder could also be a larger prime
	return m;
}
int main() {
	long long n,a;
	scanf("%lld %lld",&n,&a);
	for(int i=1;i<n;i++){
		long long ai;
		scanf("%lld",&ai);
		a=gcd(a,ai);
	}
	long long p=pgcd(a);
	if(p>1) printf("%lld\n",p);
	else printf("DNE\n");
}
