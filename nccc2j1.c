/*
Mock CCC '18 Contest 2 J1 - An Arithmetic Problem
Author: Dan Shan
Date: 2025-07-26
equality check
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a,b,c;
    char s[2];
    scanf("%d %s %d %s %d",&a,s,&b,s,&c);
    puts(a+b==c?"True":"False");
}
