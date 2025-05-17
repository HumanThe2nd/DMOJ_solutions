/*
COCI '06 Contest 1 #2 Herman
Author: Dan Shan
Date: 2024-11-26
pattern in input samples:
euclidation: pi*r^2
Taxicab: 2*r^2
*/
#include <stdio.h>
int main() {
    double r,pi=3.14159265359;
    scanf("%lf",&r);
    r*=r;
    printf("%lf\n%lf",pi*r,2*r);
}
