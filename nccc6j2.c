/*
Mock CCC '19 Contest 1 J2 - Pusheen OCR
Author: Dan Shan
Date: 2025-08-25
Compare texts
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int c=0;
    char s[8],t[]="pusheen";
    scanf("%s",s);
    for(int i=0;i<7;++i) c+=s[i]!=t[i];
    printf("%d\n",c);
}
