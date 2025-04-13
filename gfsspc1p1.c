/*
GFSSOC '15 Fall Practice P1 - Bruno and Trig
Author: HumanThe2nd
Date: 2025-04-13
if any two edges added together is less than the 3rd it's impossible for a triangle
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")  
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a) puts("Maybe I should go out to sea...");
    else puts("Huh? A triangle?");
}
