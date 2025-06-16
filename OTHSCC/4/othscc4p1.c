/*
OTHS Coding Competition 4 P1 - Square Root Decomposition
Author: Dan Shan
Date: 2025-04-29
Math Formula: Answer = 8 * R
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // Templates
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
void print(int n) { // fast output
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
int main() {
    buff();
    int n=scan();
    print(8*n);
}
