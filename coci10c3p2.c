/*
COCI '10 Contest 3 #2 Zbroj
Author: Dan Shan
Date: 2025-02-18
input both numbers as strings
add each number replacing '5's with '6's for max and vice versa
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int m=0,m2=0,min=0,max=0;
    char s=getchar();
    while(s!=' '){
        if(s=='6') s='5';
        m=m*10+s-'0';
        if(s=='5') s='6';
        m2=m2*10+s-'0';
        s=getchar();
    }
    s=getchar();
    while(s!='\n'){
        if(s=='6') s='5';
        min=min*10+s-'0';
        if(s=='5') s='6';
        max=max*10+s-'0';
        s=getchar();
    }
    printf("%d %d\n",min+m,max+m2);
}
