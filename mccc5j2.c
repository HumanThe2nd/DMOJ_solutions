/*
Mock CCC '23 Contest 1 J2 - Healthy Schedule
Author: Dan Shan
Date: 2025-08-06
Verify that values are within bounds
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int s,w;
    scanf("%d %d",&s,&w);
    int d=24-s+w;
    if(s<20||s>23||w<6||w>9||d<8||d>10) puts("Unhealthy");
    else puts("Healthy");
}
