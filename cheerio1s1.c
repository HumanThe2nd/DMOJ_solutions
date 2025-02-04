/*
Cheerio Contest 1 S1/J4 - Going to School
Author: Dan Shan
Date: 2025-02-04
Simulation with modulus
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // buffer size
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input template
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
    long long n=scan(),d=scan(),di=0,t=0;
    while(n--){
        long long pi=scan(),ri=scan(),gi=scan();
        t+=pi-di; di=pi;
        long long ti=t%(ri+gi);
        if(ti<ri) t+=ri-ti;
    }
    printf("%lld\n",t+d-di);
}
