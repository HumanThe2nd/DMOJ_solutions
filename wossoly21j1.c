/*
WOSS Dual Olympiad 2021 J1: Water Classification
Author: Dan Shan
Date: 2025-02-07
Casework
*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if(n<1) putchar('S');
    else if(n<100) putchar('L');
    else putchar('G');
    putchar('\n');
}
