/*
BlueBook - Find the Character
Author: Dan Shan
Date: 2025-08-21

1. Convert uppercase letters to lowercase (or vice versa)
2. Check equivalency
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int c=0;
    char t[2],s[1000];
    scanf("%s %[^\n]%*c",t,s);
    if(t[0]<'a') t[0]+='a'-'A';
    for(int i=0;i<1000;++i){
        if(s[i]=='\0') break;
        if(s[i]==t[0]||s[i]==t[0]-'a'+'A') ++c;
    }
    printf("%s\n%d\n",s,c);
}
