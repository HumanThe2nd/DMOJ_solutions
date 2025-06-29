/*
DMPG '15 B1 - Loner Phoner
Author: Dan Shan
Date: 2025-06-28
1. filter out invalid inputs
2. output valid numbers with hyphens and brackets
*/
#include <stdio.h>
#include<string.h>
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        char s[52];
        scanf("%s",s);
        if(strlen(s)!=10){ // length
            puts("not a phone number");
            continue;
        }
        if((s[0]!='4'||s[1]!='1'||s[2]!='6')&&(s[0]!='6'||s[1]!='4'||s[2]!='7')) { // area code
            puts("not a phone number");
            continue;
        } putchar('(');
        for(int i=0;i<3;++i) putchar(s[i]);
        putchar(')');
        putchar('-');
        for(int i=3;i<6;++i) putchar(s[i]);
        putchar('-');
        for(int i=6;i<10;++i) putchar(s[i]);
        putchar('\n');
    }
}
