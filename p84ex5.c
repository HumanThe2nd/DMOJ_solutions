/*
BlueBook - Equation
Author: Dan Shan
Date: 2025-07-23
- 2 Special cases
- Float/double division
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a==0.0) puts(b==0.0?"indeterminate":"undefined");
    else printf("%.2lf",-b/a);
}
