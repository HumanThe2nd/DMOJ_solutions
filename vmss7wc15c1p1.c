/*
VM7WC '15 #1 Bronze - Goon
Author: Dan Shan
Date: 2025-05-29
compare sums of each segment of digits
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char s[13];
    scanf("%s",s);
    int a=s[0]+s[1]+s[2],b=s[4]+s[5]+s[6],c=s[8]+s[9]+s[10]+s[11]-'0';
    if(a==b&&b==c) puts("Goony!");
    else puts("Pick up the phone!");
}
