/*
DMPG '17 B5 - Hackathons
Author: Dan Shan
Date: 2025-07-31
1. Create an array of max factor at each time value (up to max time)
2. Push the max value to the right (so t[i] is the max of the preceding times)
4. Optional: Limit the push to the max queried time

Time Compleity: O(N + max(qi) + Q)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<25 // Templates
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
    putchar('\n');
}
int t[1000001];
int main(){
    buff();
    int n=scan(),mx=1;
    while(n--){
        int ti=scan(),wi=scan();
        if(wi>t[ti]) t[ti]=wi;
    }
    int q=scan(),qi[q];
    for(int i=0;i<q;++i){
        qi[i]=scan();
        if(qi[i]>mx) mx=qi[i];
    }
    for(int i=2;i<=mx;++i) if(t[i-1]>t[i]) t[i]=t[i-1];
    for(int i=0;i<q;++i) print(t[qi[i]]);
}
