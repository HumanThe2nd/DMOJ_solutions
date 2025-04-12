/*
ECOO '13 R1 P1 - Take a Number
Author: HumanThe2nd
Date: 2025-04-11
C: total, Ci: remaining, n: number
Reset 'C' and 'Ci' each day
increment C,N & Ci when taking
decrement Ci when serving
modulo N and add 1 when printing
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")  
int main() {
   int n,c=0,ci=0;;
   scanf("%d",&n); n--;
   while(1){
    char s[6];
    scanf("%s",s);
    if(s[0]=='T') c++,ci++,n++;
    if(s[0]=='S') ci--;
    if(s[0]=='C'){
        printf("%d %d %d\n",c,ci,(n%999)+1);
        ci=0; c=0;
    }
    if(s[0]=='E') break;
   }
}
