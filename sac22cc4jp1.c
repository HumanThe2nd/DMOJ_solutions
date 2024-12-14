/*
SAC '22 Code Challenge 4 Junior P1 - Obligatory DeMello Problem
Author: Dan Shan
Date: 2024-12-13
nested for loop
*/
#include <stdio.h>
int main() {
    int c=0;
    char s[]="aeiouy";
    for(int i=5;i--;){
        char ci=getchar_unlocked();
        for(int j=0;j<6;j++) if(ci==s[j])c++;
    }
    if(c>1) puts("good\n");
    else puts("bad\n");
}
