/*
Firebending
Author: Dan Shan
Date: 2025-07-01
Add positives, subtract negatives
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<21 // Templates
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
    int n=scan(),c=0;
    while(n--){
        int ai=scan();
        if(ai>0) c+=ai;
        else c-=ai;
    }
    printf("%d\n",c);
}
