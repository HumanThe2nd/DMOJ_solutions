/*
DMOPC '20 Contest 1 P1 - Victor Gets Quizzed
Author: HumanThe2nd
Date: 2025-04-28
count frequencies of 'M' & 'C'
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        char s[6];
        scanf("%s",s);
        int c=0;
        for(int i=0;i<5;i++) c+=(s[i]=='M'||s[i]=='C');
        if(!c) puts("PASS");
        else if(c==1) puts("FAIL");
        else puts("NEGATIVE MARKS");
    }
}
