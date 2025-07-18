/*
Bob's Temple
Author: Dan Shan
Date: 2025-07-17
1. Store frequency of each element
2. Print first freuqnecy of each in increasing order
3. Print the rest in non-increasing order
Optional optimization: Only iterate up to the highest valid number (instead of 1e6)

Time Complexity: O(N + max(Ai))
*/
#include <stdio.h>
#include <stdlib.h>
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
}
int v[1000001];
int main(){
    buff();
    int n=scan(),m=1;
    for(int i=0;i<n;++i){
        int ai=scan();
        if(ai>m) m=ai;
        ++v[ai];
    }
    int res[n],r=0;
    for(int i=1;i<=m;++i) if(v[i]) res[r++]=i;
    for(int i=m;i>0;--i) while(v[i]>1) res[r++]=i,--v[i];
    print(res[0]);
    for(int i=1;i<n;++i) putchar(' '),print(res[i]);
    putchar('\n');
}
