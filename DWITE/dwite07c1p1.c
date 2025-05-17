/*
DWITE '07 R1 #1 - Vanilla Primes
Author: Dan Shan
Date: 2025-02-08
template prime checker
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n;
    scanf("%d",&n);
    if(n<2) return puts("not")*0;
    for(int i=2;i*i<=n;i++){
        if(!(n%i)) return puts("not")*0;
    }
    puts("prime");
}
