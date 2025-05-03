/*
WOSS Dual Olympiad 2023 J2: 3 Numbers
Author: HumanThe2nd
Date: 2025-05-03
Brute Force every combination
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ai=a*b+c,bi=a*c+b,ci=b*c+a,di=a+b+c,ei=a*b*c,fi=a*(b+c),gi=(a+b)*c,hi=(a+c)*b;
    if(bi>ai) ai=bi;
    if(ci>ai) ai=ci;
    if(di>ai) ai=di;
    if(ei>ai) ai=ei;
    if(fi>ai) ai=fi;
    if(gi>ai) ai=gi;
    if(hi>ai) ai=hi;
    printf("%d\n",ai);
}
