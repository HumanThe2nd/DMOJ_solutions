/*
Mock CCC '20 S1 - War
Author: Dan Shan
Date: 2025-09-01

count chains of equal values
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
int main() {
    buff();
    int n=scan();
    int a[n],c=0,l=1;
    for(int i=0;i<n;++i) a[i]=scan();
    for(int i=0;i<n;++i){
        int ai=scan();
        if(ai==a[i]) {
            if(l) c++,l=0;
        }
        else l=1;
    }
    printf("%d\n",c);
}
