/*
BlueBook - Interest
Author: HumanThe2nd
Date: 2025-04-12
Multiply money by (100+interest)/100 each time
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")  
int main() {
   double n;
   int a,b;
   scanf("%lf %d %d",&n,&a,&b);
   a+=100;
   for(int i=0;i<=b;i++){
    printf("%d %0.2lf\n",i,n);
    n=(n*a)/100;
   }
}
