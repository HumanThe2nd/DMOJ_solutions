/*
Mock CCO '18 Contest 3 Problem 4 - Roger Solves A Classic Rage Tree Problem
Author: Dan Shan
Date: 2025-06-01
Sparse table for max and min
Take difference for each query
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
typedef long long ll;
#define bs 1<<24 // Templates
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
void print(int n) {
    if(!n) putchar('0');
    char s[10];
    int i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar(s[i]);
    }
    putchar('\n');
}
int mn[17][50001],mx[17][50001];
int main(){
    buff();
    int n=scan(),q=scan(),a[n];
    for(int i=0;i<n;++i){
        a[i]=scan();
        mn[0][i]=a[i]; mx[0][i]=a[i];
    }
    for(int i=1;(1<<i)<=n;++i){ // build
    for(int j=0;(j+(1<<i)-1)<n;++j){ 
        if(mn[i-1][j]<mn[i-1][j+(1<<(i-1))]) mn[i][j]=mn[i-1][j];
        else mn[i][j]=mn[i-1][j+(1<<(i-1))];
        if(mx[i-1][j]>mx[i-1][j+(1<<(i-1))]) mx[i][j]=mx[i-1][j];
        else mx[i][j]=mx[i-1][j+(1<<(i-1))];
    }
    }
    while(q--){
        int ai=scan(),bi=scan(),pi=0,l,r;
        --ai; --bi;
        while((1<<(pi+1))<=bi-ai+1) ++pi;
        if(mn[pi][ai]<mn[pi][bi-(1<<pi)+1]) l=mn[pi][ai];
        else l=mn[pi][bi-(1<<pi)+1]; // min
        if(mx[pi][ai]>mx[pi][bi-(1<<pi)+1]) r=mx[pi][ai];
        else r=mx[pi][bi-(1<<pi)+1]; // max
        print(r-l);
    }
}
