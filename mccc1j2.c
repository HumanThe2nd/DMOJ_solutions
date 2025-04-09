/*
Mock CCC '20 Contest 1 J2 - A Simplex Problem
Author: HumanThe2nd
Date: 2025-04-09
Max(Uc,Um) * K
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   if(a<b) a=b;
   printf("%d\n",b*c);
}
