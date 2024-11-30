/*
Raytracing
Author: Dan Shan
Date: 2024-11-30
Brute Force between intervals
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
void print(int n) {
    if(!n) putchar_unlocked('0');
    char s[10];
    int i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar_unlocked(s[i]);
    }
    putchar_unlocked('\n');
}
int main() {
    int n=scan();
    int a[n];
    for(int i=0;i<n;i++) a[i]=scan();
    int q=scan();
    while(q--){
        int qi=scan();
        if(qi==2){
            int ai=scan(),bi=scan();
            a[ai]=bi;
            continue;
        }
        int c=0,ai=scan(),bi=scan(),hi=scan(),hf=scan();
        for(int i=ai;i<=bi;i++){
            if(a[i]>=hi&&a[i]<=hf)c++;
        }
        print(c);
    }
}
