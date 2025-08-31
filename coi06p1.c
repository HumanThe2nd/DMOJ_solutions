/*
COI '06 #1 Patrik
Author: Dan Shan
Date: 2025-08-30
Monotonic stack
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
typedef struct {int h,c;} node;
int main() {
    buff();
    int n=scan(), l=0;
    node stk[n];
    long long c=0;
    while(n--){
        int ai=scan(),ci=1;
        while(l && ai >= stk[l-1].h){ // block shorter people
            --l; c += stk[l].c;
            if(stk[l].h == ai) ci += stk[l].c;
        }
        if(l) ++c;
        stk[l].h = ai; stk[l++].c = ci;
    }
    printf("%lld\n",c);
}
