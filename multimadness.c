/*
Multiplication Madness
Author: Dan Shan
Date: 2024-11-12
Theory: Precompute factor up to each number
divide the larger by the smaller for each query
fermat's little theorem is used to find modulus inverse and optimize
*/
#include <stdio.h>
long long a[1000001],m=1e9+7;
long long mod(long long b, long long e){
	long long res=1;
	while(e>0){
		if(e&1){
			res=(res*b)%m;
		}
		e>>=1;
		b=(b*b)%m;
	}
	return res;
}
int main() {
	a[0]=1;
	for(int i=1;i<1000001;i++){
		a[i]=a[i-1]*i;
		a[i]%=m;
	}
	int n;
	scanf("%d",&n);
	while(n--){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",(a[y]*mod(a[x-1],m-2)%m));
	}
}
