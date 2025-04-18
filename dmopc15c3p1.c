/*
DMOPC '15 Contest 3 P1 - Quality Scenes
Author: HumanThe2nd
Date: 2025-04-17
If both start times are greater than the end times of the other, it overlaps
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(b>c&&d>a) puts("YES");
    else puts("NO");
}
