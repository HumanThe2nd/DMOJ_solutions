/*
COCI '19 Contest 4 #2 Spiderman
Author: Dan Shan
Date: 2025-08-22

1. Sieve all larger numbers marking valid cells
2. Special case (k = 0) remove one occurence (itself)
Referenced this code for debugging: https://github.com/vishnupsatish/dmoj-practice/blob/master/coci19c4p2.cpp
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
int c[1000001],v[1000001];
int main(){
    buff();
    int n=scan(),k=scan(),a[n],mx=1;
    for(int i=0;i<n;++i){
        a[i]=scan();
        if(a[i]>mx) mx=a[i];
        ++c[a[i]];
    }
    for(int i=0;i<=mx;++i){
        if(!c[i]) continue;
        v[i]-=k==0;
        if(i>k){
            for(int j=k;j<=mx;j+=i) v[j]+=c[i];
        }
    }
    for(int i=0;i<n;++i){
        if(i) putchar(' ');
        printf("%d",v[a[i]]);
    }
    putchar('\n');
}
