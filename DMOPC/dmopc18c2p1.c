/*
DMOPC '18 Contest 2 P1 - Pumpkin Patches
Author: Dan Shan
Date: 2025-05-24
find min and max values for both coords
take the sum of change in x and change in y, then multiply by 2
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int p,xi,xf,yi,yf;
    scanf("%d %d %d",&p,&xi,&yi);
    xf=xi; yf=yi;
    while(--p){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x<xi) xi=x;
        else if(x>xf) xf=x;
        if(y<yi) yi=y;
        else if(y>yf) yf=y;
    } xf-=xi; yf-=yi;
    printf("%d\n",(yf+xf)<<1);
}
