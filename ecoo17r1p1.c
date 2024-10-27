/*
ECOO '17 R1 P1 - Munch 'n' Brunch
Author: Dan Shan
Date: 2024-10-27
if money made < 2*money needed: YES
else NO
note: track greatest percentage and add missing people to that group to avoid spliting people
*/
#include <stdio.h>
int main() {
    for(int t=10;t;t--){
    int ct,n;
    double a,b,c,d,m;
    scanf("%d%lf%lf%lf%lf%d",&ct,&a,&b,&c,&d,&n);
    int ca=n*a,cb=n*b,cc=n*c,cd=n*d; m=a;
    if(b>m) m=b;
    if(c>m) m=c;
    if(d>m) m=d;
    int diff=n-ca-cb-cc-cd;
    if(a==m) ca+=diff;
    else if(b==m) cb+=diff;
    else if(c==m) cc+=diff;
    else if(d==m) cd+=diff;
    ca*=12; cb*=10; cc*=7; cd*=5;
    printf("%s\n",ca+cb+cc+cd<2*ct?"YES":"NO");
    }
}
