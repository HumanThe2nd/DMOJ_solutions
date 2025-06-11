/*
DMOPC '17 Contest 2 P0 - Secrets
Author: Dan Shan
Date: 2025-06-11
Use Pythagorean theorem to compare distances
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int x1,y1,x2,y2,xs,ys,d;
    scanf("%d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&xs,&ys,&d);
    x1-=xs; y1-=ys; x2-=xs; y2-=ys;
    if(x1*x1+y1*y1>d*d&&x2*x2+y2*y2>d*d) puts("No");
    else puts("Yes");
}
