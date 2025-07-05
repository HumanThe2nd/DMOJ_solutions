/*
DMPG '19 B3 - Contact
Author: Dan Shan
Date: 2025-07-04
1. count consecutive 'S' chars
2. if ever equal to k: Spamming, else: All Good
*/
#include <stdio.h>
int main() {
    char s[2001];
    int k,c=0;
    scanf("%s %d",s,&k);
    for(int i=0;i<2001;++i){
        if(s[i]=='\0') break;
        if(s[i]=='S') ++c;
        else c=0;
        if(c==k) return !puts("Spamming");
    }
    puts("All good");
}
