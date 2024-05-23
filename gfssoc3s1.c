// GFSSOC '15 Winter S1 - OR-deal
// By: Dan Shan
// Note: Horribly worded problem
// find length in binary and print a 1 for each digit
#include <stdio.h>
int main() {
	long long n;
    scanf("%lld",&n);
    int l=0;
    while(n){
        l++;
        n>>=1;
    }
    while(l--) printf("1");
    printf("\n");
}
