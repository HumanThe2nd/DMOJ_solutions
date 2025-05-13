/*
GFSSOC '15 Winter J2 - Purchasing Presents
Author: Dan Shan
Date: 2025-05-12
Subtract all input values from initial
Note: 9/10 passes without setting vlaues of -1e-3 to 0 for precision  
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int n;
    double c;
    scanf("%d %lf",&n,&c);
    while(n--){
        double ci;
        scanf("%lf",&ci);
        c-=ci;
    }
    if(c>=-1e-3) printf("%0.2lf\n",c>0?c:0); // floating point imprecision
    else puts("Fardin's broke");
}
