/*
ICPC SWERC 2017 F - Shattered Cake
Author: Dan Shan
Date: 2025-09-07

Length = (Sum of fragment sizes) / Width
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<25 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int main() {
    buff();
    long long w = scan(), n = scan(),c=0;
    while(n--){
        long long ai = scan(), bi = scan();
        c += ai*bi;
    }
    printf("%lld\n", c/w);
}
