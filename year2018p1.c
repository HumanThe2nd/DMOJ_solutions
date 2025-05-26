/*
New Year's '18 P1 - Happy New Year!
Author: Dan Shan
Date: 2025-05-26
Use a large multiple of 3600 as the initial time and subtract the change
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    long long h,m,s,t=167961600000000;
    scanf("%lld %lld %lld",&h,&m,&s);
    t-=s+m*60+h*3600;
    int hf=(t/3600)%12,mf=(t/60)%60,sf=t%60;
    if(hf<10) putchar('0'); // leading zero
    printf("%d:",hf);
    if(mf<10) putchar('0');
    printf("%d:",mf);
    if(sf<10) putchar('0');
    printf("%d\n",sf);
}
