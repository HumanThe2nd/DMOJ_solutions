/*
DMOPC '19 Contest 5 P0 - Concurrent Competitor Counting
Author: Dan Shan
Date: 2025-06-25
score > cutoff: advance
else: will not advance
*/
#include <stdio.h>
int main() {
    int n,c,ci;
    scanf("%d %d",&n,&c);
    while(n--){
        char s[51];
        scanf("%s %d",s,&ci);
        if(ci>c) printf("%s will advance\n",s);
        else printf("%s will not advance\n",s);
    }
}
