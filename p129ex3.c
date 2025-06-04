/*
BlueBook - Powers of 2
Author: Dan Shan
Date: 2025-06-03
Brute force first power of 2 not less than 'n'
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,p=1,c=0;
    scanf("%d",&n);
    while(p<n) p<<=1,++c;
    printf("%d\n",c);
}
