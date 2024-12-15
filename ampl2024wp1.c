/*
Amplitude Hackathon Winter '24 Problem 1 - Twila's Walk
Author: Dan Shan
Date: 2024-12-14
square input and output
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
int main() {
    int x=scan();
    print(x*x);
    putchar_unlocked('\n');
}
