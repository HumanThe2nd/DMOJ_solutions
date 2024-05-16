// WC '96 P6 - Bases Multiplication
// By: Dan Shan
#include <stdio.h>
#include <math.h>
#define s(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	for(int t=0;t<2;t++){
		int a,a2,b,b2,b3,c=0,c2=0,i=0;
		s(a); s(b); s(a2); s(b2); s(b3);
		while(a>0){
			c+=(a%10)*pow(b,i);
			a/=10;
			i++;
		} i=0;
		while(a2>0){
			c2+=(a2%10)*pow(b2,i);
			a2/=10;
			i++;
		}
		int p = c*c2; i=0;
		long long res=0;
		while(p>0){
			res+=(p%b3)*pow(10,i);
			p/=b3;
			i++;
		}
		printf("%lld\n",res);
	}
}
