/*
Double Doors Regional P1 - Tudor Gets a Goat
Author: HumanThe2nd
Date: 2025-03-08
if selected has car or opened by host, switch
otherwise, stay
*/
#include <stdio.h>
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b||b==c) puts("Switch");
    else puts("Stay");
}
