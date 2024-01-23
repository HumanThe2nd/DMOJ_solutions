// Cheerio Contest 2 P3 - Digits
// By: Dan Shan
// simple pattern tracing
#include <stdio.h>
#define MIN(a,b)((a)>(b)?(b):(a))
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
long long int x,y,q;
scanf("%lld %lld %lld",&x,&y,&q);
long long int d = MIN(x,y),l = x+y,m = MAX(x,y);
for(int i=0;i<q;i++){
	long long int n;
	scanf("%lld",&n);
	if(n<d) printf("9\n");
	else if(n==d) printf("8\n");
	else if(n==l)printf("1\n");
	else if(n<=d+m-d)printf("9\n");
	else printf("0\n");
}
}
