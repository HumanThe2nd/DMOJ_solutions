/*
DMOPC '17 Contest 5 P1 - IOI 101
Author: Dan Shan
Date: 2025-05-09
Brute force replacements
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char s[1001],al[]={'O','l','2','E','A','S','G','7','B','g'};
    scanf("%s",s);
    for(int i=0;i<1001;i++){
        if(s[i]=='\0') break;
        if(s[i]<'0'||s[i]>'9') continue;
        s[i]=al[s[i]-'0'];
    }
    puts(s);
}
