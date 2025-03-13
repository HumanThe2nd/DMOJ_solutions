/*
DWITE '07 R1 #2 - Cubes in a Pyramid
Author: HumanThe2nd
Date: 2025-03-13
Cubes = Ceil(volume) = b*h*l/3
Cubes = a*a*b/3
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%d\n",(int)(a*a*b/3+0.999999999999));
}
