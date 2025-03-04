/*
CPC '21 Contest 1 P0 - AQT and Alphabet
Author: HumanThe2nd
Date: 2025-03-03
Create visited array of the alphabet and iterate
*/
#include <stdio.h>
int a[26];
int main() {
    char s[6];
    scanf("%s",s);
    for(int i=0;i<6;i++){
        if(s[i]=='\0') break;
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++) if(!a[i]) return putchar(i+'a')*0;
}
