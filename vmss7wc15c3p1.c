/*
VM7WC '15 #3 Bronze - M's Theorem!
Author: Dan Shan
Date: 2025-02-08
vector addition using x and y components
arcsin yields angles from -180 to 180 but output requires 0 to 360
flip negative angles theta to  arcsin to 180-theta to yield the 360 degree angle
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n;
    double r=0.0174532925,x=0,y=0; // r: degrees to radians
    scanf("%d",&n);
    while(n--){
        double ai,bi;
        scanf("%lf %lf",&ai,&bi);
        x+=ai*sin(bi*r),y+=ai*cos(bi*r);
    }
    double mi=sqrt(x*x+y*y),ai=asin(x/mi)/r;
    if(ai<0) ai=180-ai;
    printf("%0.lf %0.lf\n",mi,ai);
}
