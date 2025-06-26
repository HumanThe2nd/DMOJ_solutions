/*
DMOPC '19 Contest 2 P0 - Roller Coaster
Author: Dan Shan
Date: 2025-06-26
Count heights <= hmax and >= hmin
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
    int n=scan(),hi=scan(),hf=scan(),c=0;
    while(n--){
        int ai=scan();
        c+=(hi<=ai&&ai<=hf);
    }
    printf("%d\n",c);
}
