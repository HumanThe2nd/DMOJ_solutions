/*
DWITE '07 R4 #1 - Curve-shot
Author: Dan Shan
Date: 2025-05-11
Kinematic equations / Projectile motion
t = (Viy / a) * 2 (since start and end are same elevation)
d = Vix * t
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int main(){
    buff();
    double rad = 0.0174532925;
    for(int t=5;t--;){
        double ai=scan(),pi=scan();
        double px=pi*sin(rad*ai),py=pi*cos(rad*ai);
        double ti=2*(px/9.81);
        printf("%0.lf\n",ti*py);
    }
}
