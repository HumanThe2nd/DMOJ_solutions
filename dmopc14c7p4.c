/*
DMOPC '14 Contest 7 P4 - Sand Triangle
Author: Dan Shan
Date: 2025-02-21
subtract integers from 1 to infinity from n until: n > 0
compute sum of a row using: S = l(2 * a1 + l - 1)/2, where a1 is the first element in the row
(simplfied arithmetic series equation)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    long long n,a1=1,l=1;
    scanf("%lld",&n);
    while(n>0){
        n-=l;
        a1+=l;
        l++;
    } --l; 
    a1-=l;
    printf("%lld\n",l*(2*a1+l-1)/2);
}
