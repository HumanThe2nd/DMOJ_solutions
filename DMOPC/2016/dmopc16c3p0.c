/*
DMOPC '16 Contest 3 P0 - Negative Feedback
Author: HumanThe2nd
Date: 2025-04-07
Plug into formula and round to 3 deciaml places
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    double vi,rf,rg;
    scanf("%lf %lf %lf",&vi,&rf,&rg);
    printf("%0.2lf\n",vi*(1+rf/rg));
}
