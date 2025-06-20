/*
Another Contest 7 Problem 2 - Code Review
Author: Dan Shan
Date: 2025-02-25
swap each invalid character with the next
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
void print(int n) { // fast output template
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
    putchar(' ');
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++) a[i]=i;
    while(1){
        for(int i=1;i<=n;i++){
            print(a[i]);
        }
        putchar('\n');
        fflush(0);
        int ai;
        scanf("%d",&ai);
        if(!ai) return 0;
        if(ai<0) return puts("-1")*0;
        int temp=a[ai];
        a[ai]=a[ai%n+1];
        a[ai%n+1]=temp; // swap invalid cells with the next
    }
}
