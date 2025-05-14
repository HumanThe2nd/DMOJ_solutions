/*
OTHS Coding Competition 3 (Mock CCC) S1 - The 5th Laboratory
Author: Dan Shan
Date: 2024-12-09
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){ // solution
    int xl,yl,zl,n;
    scanf("%d %d %d %d",&xl,&yl,&zl,&n);
    double min = 2e9;
    for(int i=0;i<n;i++){
        int xi,yi,zi;
        scanf("%d %d %d",&xi,&yi,&zi);
        double h = (sqrt(pow(xi-xl,2)+pow(yi-yl,2))),v=abs(zi-zl);
        if(zi>zl) {
            v/=4; // glide 4 times faster than climbing
            h-=3*v; // glide partial horizontal distance
            if(h<0) h=0; // can't glide past
        }
        v+=h/2; // total time
        if(v<min) min=v;
    }
    printf("%lf\n",min);
}
