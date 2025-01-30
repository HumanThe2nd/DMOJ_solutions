/*
VMSS Pre-Windsor P5 - Math Depression
Author: Dan Shan
Date: 2025-01-29
Split the number into 3s and 2s where the number of 3s are maximized
*/
#include <stdio.h>
int main(){
    long long n,c=1,m=1e9+7;
    scanf("%lld ",&n);
    while(n>4){
        c*=3;
        n-=3;
        c%=m;
    }
   if(n) c=(c*n)%m;
   printf("%lld\n",c);
}
