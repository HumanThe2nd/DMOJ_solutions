/*
CSPC '15 #2 - Build Season
Author: Dan Shan
Date: 2025-06-21
Formula: t = 6n + (7 - w)h
** if w == 0 , h = 7
*/
#include <stdio.h>
int main() {
    int n,w,h=7;
    scanf("%d %d",&n,&w);
    if(w) scanf("%d",&h);
    printf("It takes %d hours for Team 610 build a robot.\n",6*n+(7-w)*h);
}
