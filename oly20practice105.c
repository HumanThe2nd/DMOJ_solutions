/*
Bob's Backyard
Author: Dan Shan
Date: 2025-08-26
res = (n-1) * (m-1)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    long long n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",(n-1)*(m-1));
}
