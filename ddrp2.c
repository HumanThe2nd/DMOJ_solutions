/*
Double Doors Regional P2 - Tudor Learns DDR
Author: Dan Shan
Date: 2025-06-20
Casework
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char s[4];
    scanf("%s",s);
    if((s[0]=='L'||s[0]=='R')&&(s[2]=='L'||s[2]=='R')&&s[0]!=s[2]&&s[1]!='L'&&s[1]!='R') puts("Crossover");
    else if((s[0]=='U'||s[0]=='D')&&(s[2]=='U'||s[2]=='D')&&s[0]!=s[2]&&s[1]!='U'&&s[1]!='D') puts("Candle");
    else puts("Neither");
}