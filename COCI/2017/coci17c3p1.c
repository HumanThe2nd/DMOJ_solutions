/*
COCI '17 Contest 3 #1 Aron
Author: Dan Shan
Date: 2025-08-07
count characters that don't match previous
*/
#include <stdio.h>
int main() {
    int n,c=1;
    char l='&';
    scanf("%d",&n);
    while(n--){
        char s[2];
        scanf("%s",s);
        if(s[0]==l) continue;
        l=s[0]; ++c;
    }
    printf("%d",c);
}
