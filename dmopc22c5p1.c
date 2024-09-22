// DMOPC '22 Contest 5 P1 - Triple Triplets
// Author: Dan Shan
// Date: 2024-09-22
// Combinatorics formula: N choose k where k=2
#include <stdio.h>
int main() {
    long long n,m=0;
	scanf("%lld",&n);
    for(int i=1;i*2<n;i++){
        long long ai=i*(n-2*i)*(n-2*i-1)/2;
        if(ai>m) m=ai;
    }
    printf("%lld\n",m);
}
