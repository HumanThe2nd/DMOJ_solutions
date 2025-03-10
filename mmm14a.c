/*
MMM '14 A - Distinct Prime Factors
Author: HumanThe2nd
Date: 2025-03-10
Prime sieve with frequency array
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
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
int s[1000001];
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=2;i<b;i++){
        if(s[i]) continue;
        for(int j=i;j<=b;j+=i) s[j]++;
    }
    for(int i=a;i<=b;i++) print(s[i]);
}
