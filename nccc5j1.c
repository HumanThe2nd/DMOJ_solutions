/*
Mock CCC '18 Contest 5 J1 - Looking for the CCC
Author: Dan Shan
Date: 2025-09-24
Check every 3 adjacent characters
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    char s[11];
    scanf("%s",s);
    for(int i = 2; i < 11; ++i){
        if(s[i] == '\0' || s[i-1] == '\0') break;
        if(s[i] == 'C' && s[i-1] == 'C' && s[i-2] == 'C') return !puts("NO");
    }
    puts("YES");
}
