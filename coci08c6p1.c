/*
COCI '08 Contest 6 #1 Buka
Author: HumanThe2nd
Date: 2025-03-24
l: string1 length, l2: string2 length
multiplication -> 1 trailed by l+l2-2 zeros
addition: l1 equal l2? -> 2 trailed by l1-1 zeros
otherwise: 
    l3: max (l, l2)
    iterate maximum, print 1 at l3-l and l3-l2 and 0 otherwise
*/
#include <stdio.h>
#include <string.h>
#pragma GCC optimize("Ofast")
int main() {
    char s[101],s2[2],s3[101];
    scanf("%s %s %s",s,s2,s3);
    int l=strlen(s),l2=strlen(s3);
    if(s2[0]=='*'){
        putchar('1');
        for(int i=2;i<l+l2;i++) putchar('0');
    }
    else{
        if(l==l2){
            putchar('2');
            for(int i=1;i<l;i++) putchar('0');
        }
        else{
            int l3=l;
            if(l2>l3) l3=l2;
            for(int i=0;i<l3;i++){
                putchar((l3-i==l||l3-i==l2)?'1':'0');
            }
        }
    }
    putchar('\n');
}
