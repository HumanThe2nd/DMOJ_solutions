/*
DMPG '18 B1 - Pizza Orders
Author: Dan Shan
Date: 2025-03-04
ceil each number divided by 3 and take the sum
*/
#include <stdio.h>
int main() {
    long long p,c,v;
    scanf("%lld %lld %lld",&p,&c,&v);
    printf("%lld\n",(p+2)/3+(c+2)/3+(v+2)/3);
}
