/*
CPC '19 Contest 1 P0 - Shoes
Author: Dan Shan
Date: 2025-03-08
Only need to check 1st 2 shoes
*/
#include <stdio.h>
int main() {
    char s[3][2];
    scanf("%s %s %s",s[0],s[1],s[2]);
    if(s[0][0]==s[2][0]) puts("1 2\n3 4");
    else puts("1 3\n2 4");
}
