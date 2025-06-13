/*
DMOPC '19 Contest 1 P0 - Range Finding
Author: Dan Shan
Date: 2025-06-12
Subtract min from max
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
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
int main(){
    buff();
    int n=scan(),a=scan(),b=a;
    for(int i=1;i<n;++i) {
        int ai=scan();
        if(ai<a) a=ai;
        if(ai>b) b=ai;
    }
    printf("%d\n",b-a);
}
