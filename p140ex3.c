/*
BlueBook - Column of Numbers
Author: Dan Shan
Date: 2025-08-23
print string backwards
*/
#include <stdio.h>
#include <string.h>
#pragma GCC optimize("Ofast")
int main() {
    char s[100001];
    scanf("%s",s);
    int l=strlen(s);
    while(--l>=0) printf("%c\n",s[l]);
}
