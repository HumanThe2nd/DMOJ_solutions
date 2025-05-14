/*
OTHS Coding Competition 3 (Mock CCC) S4 - Magic Library
Author: Dan Shan
Date: 2025-05-14
Square Root Decomposition + Lazy Propagation + Frequency arrays
Store lazy queries in blocks of sqrt(n)
Update: 
1. Update lazy for full blocks
2. Update all cells in partial blocks and reset the lazy
Query: 
1. add each lazy block equal to target
2. brute force search the partial blocks
Note: copied segments from GPT, as code became too lengthy to debug efficiently
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma GCC optimize ("Ofast")
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
inline void print(int n) {
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
int a[1000001],lazy[1001],f[1001][501];
int main(){
    buff();
    int n=scan(),q=scan(),m=sqrt(n);
    for(int i=0;i<n;i++) {
        a[i]=scan();
        f[i/m][a[i]]++;
    }
    while(q--){
        int ti=scan(),li=scan()-1,ri=scan()-1,vi=scan();
        int si=li/m,ei=ri/m; // 
        if(ti==1){ // update
            if(si==ei){
                if(lazy[si]){
                    for(int i=si*m;i<(si+1)*m&&i<n;++i) {
                        a[i]=lazy[si];
                        f[si][lazy[si]]++;
                    }
                    memset(f[si],0,sizeof(f[si]));
                    for(int i=si*m;i<(si+1)*m&&i<n;++i) f[si][a[i]]++;
                    lazy[si]=0;
                    for(int i=li;i<=ri;++i){
                    f[si][a[i]]--;
                    a[i] = vi;
                    f[si][a[i]]++;
                }
                }
                for(int i=li;i<=ri;++i) {
                    f[si][a[i]]--;
                    a[i]=vi;
                    f[si][a[i]]++;
                }        
            }
            else{
                if(lazy[si]){
                    for(int i=si*m;i<(si+1)*m&&i<n;++i){
                        a[i]=lazy[si];
                    }
                    memset(f[si], 0, sizeof(f[si]));
                    for(int i=si*m;i<(si+1)*m&&i<n;++i)
                        f[si][a[i]]++;
                    lazy[si]=0;
                }
                for(int i=li;i<(si+1)*m;++i){
                    f[si][a[i]]--;
                    a[i] = vi;
                    f[si][a[i]]++;
                }

                for(int i=si+1;i<ei;++i){
                    lazy[i]=vi;
                    memset(f[i], 0, sizeof(f[i]));
                    f[i][vi]=m;
                }

                if(lazy[ei]){
                    for(int i=ei*m;i<(ei+1)*m&&i<n;++i){
                        a[i]=lazy[ei];
                    }
                    memset(f[ei], 0, sizeof(f[ei]));
                    for(int i=ei*m;i<(ei+1)*m&&i<n;++i)
                        f[ei][a[i]]++;
                    lazy[ei]=0;
                }
                for(int i=ei*m;i<=ri;++i){
                    f[ei][a[i]]--;
                    a[i] = vi;
                    f[ei][a[i]]++;
                }
            }
        }
        else{ // query
            int res=0;
            if(si==ei){
                for(int i=li;i<=ri;++i){
                    int val=lazy[i/m]?lazy[i/m]:a[i];
                    res+=val==vi;
                }
            }
            else{
                for(int i=li;i<(si+1)*m;++i){ // left
                    int val=lazy[i/m]?lazy[i/m]:a[i];
                    res+=val==vi;
                }
                for(int i=ei*m;i<=ri;++i){ // right
                    int val=lazy[i/m]?lazy[i/m]:a[i];
                    res+=val==vi;
                }
                for(int i=si+1;i<ei;++i) { // full block
                    if(lazy[i]) res+=(lazy[i]==vi)*m;
                    else res+=f[i][vi];
                }
            }
            print(res);
        }
    }
}
