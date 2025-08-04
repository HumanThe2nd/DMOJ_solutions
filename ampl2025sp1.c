/*
Amplitude Hackathon Summer '25 Problem 1 - AI (Easy)
Author: Dan Shan
Date: 2025-08-04
Check each pair of indexes
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        char s[51];
        scanf("%s",s);
        int f=1,i;
        for(i=1;i<50;++i){
            if(s[i]=='\0') break;
            if(s[i-1]=='A'&&s[i]=='I'){
                puts("YES");
                f=0; break;
            }
        }
        if(f) puts("NO");
    }
}
