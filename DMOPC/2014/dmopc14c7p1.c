/*
DMOPC '14 Contest 7 P1 - Flare
Author: Dan Shan
Date: 2025-02-15
0=vt+0.5at^2
vt=0.5at^2 balance
v=0.5at cancel t
t = 2*v/a isolate t
t = v/4.9 simplify constants
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int v;
    scanf("%d",&v);
    printf("%lf\n",v/4.9);
}
