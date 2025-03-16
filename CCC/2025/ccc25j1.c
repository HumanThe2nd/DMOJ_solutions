/*
CCC '25 J1 - Roller Coaster Ride
Author: HumanThe2nd
Date: 2025-03-15
Check if C * Q is less than N
*/
#include <stdio.h>
int main(){
    int n,c,q;
    scanf("%d %d %d",&n,&c,&q);
    if(c*q<n) puts("no");
    else puts("yes");
}
