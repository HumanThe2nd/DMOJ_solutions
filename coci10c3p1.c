/*
COCI '10 Contest 3 #1 Tablica
Author: Dan Shan
Date: 2025-01-17
Brute force
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    double r=0,m=a/c+b/d;
    if(b/a+d/c>m){
        m=b/a+d/c; r=3;
    }
    if(d/b+c/a>m){
        m=d/b+c/a; r=2;
    }
    if(a/b+c/d>m){
        m=a/b+c/d; r=1;
    }
    printf("%0.0lf\n",r);
}
