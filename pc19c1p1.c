/*
CPC '19 Contest 1 P1 - Distance
Author: Dan Shan
Date: 2025-01-07
Alternate from lowest to highest until finished
*/
#include <stdio.h>
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
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        print((i&1)?(i+1)/2:n-(i-1)/2);
        putchar(i==n?'\n':' ');
    }
}
