/*
SAC '22 Code Challenge 4 Junior P2 - Obligatory Geometry Problem
Author: Dan Shan
Date: 2024-12-13
Array queries
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
void print(long long n) {
    if(!n) putchar_unlocked('0');
    char s[20];
    long long i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar_unlocked(s[i]);
    }
}
int a[100001];
int main() {
    int n=scan(),q=scan();
    while(q--){
        char qi=getchar_unlocked();
        for(int i=0;i<3;i++) getchar_unlocked();
        char shape=getchar_unlocked();
        int ai=scan(),f=0;
        if(qi=='s'){
            if(shape=='s') a[ai]=1;
            else if(shape=='c') a[ai]=2;
            else if(shape=='t') a[ai]=3;
        }
        else{
            if(shape=='s'&&a[ai]==1) f=1;
            else if(shape=='c'&&a[ai]==2)f=1;
            else if(shape=='t'&&a[ai]==3)f=1;
            print(f);
            putchar_unlocked('\n');
        }
    }
}
