// DMOPC '22 Contest 3 P1 - Holiday Colouring
// By: Dan Shan
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
    long long n,m;
    scanf("%lld %lld",&n,&m);
    long long h = n*m/2,mx = MAX(n*(m/2),m*(n/2));
    if((n*m)&1)printf("%lld %lld\n",n*m-mx,mx);
    else printf("%lld %lld\n",h,h);
}
