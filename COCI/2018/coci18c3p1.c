/*
COCI '18 Contest 3 #1 Magnus
Author: Dan Shan
Date: 2025-06-04
Track each subsequence of the string "HONI"
if a letter matches any, check if the last matched letetr was the one before
Count full subsequences formed
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char s[100001],cl='H';
    scanf("%s",s);
    int l=0,c=0;
    while(s[l]!='H'&&s[l]!='\0') ++l;
    ++l;
    while(s[l]!='\0'){
        char si=s[l++];
        if(cl=='H'&&si=='O') cl='O';
        else if(cl=='O'&&si=='N') cl='N';
        else if(cl=='N'&&si=='I') cl='I';
        else if(cl=='I'&&si=='H') cl='H',++c;
    }
    if(cl=='I') ++c;
    printf("%d\n",c);
}
