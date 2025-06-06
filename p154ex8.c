/*
BlueBook - Exact Divisors
Author: Dan Shan
Date: 2025-06-05
Brute force with modulus
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) if(n%i==0) printf("%d\n",i);
}
