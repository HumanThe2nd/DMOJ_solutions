/*
OTHS Coding Competition 2 P1 - Chess Pieces
Author: Dan Shan
Date: 2024-07-23
Brute force all pieces (note we only need first letter)
*/
#include <stdio.h>
int main() {
    char s[7];
    scanf("%s",s);
    if(s[0]=='p') putchar('1');
    else if(s[1]=='n'||s[0]=='b') putchar('3');
    else if(s[0]=='r') putchar('5');
    else if(s[0]=='q') putchar('9');
    else printf("priceless");
    putchar('\n');
}
