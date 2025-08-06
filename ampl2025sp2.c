/*
Amplitude Hackathon Summer '25 Problem 2 - AI (Also Easy)
Author: Dan Shan
Date: 2025-08-05
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        char s[51];
        scanf("%s",s);
        int f=1,a=0,i;
        for(i=0;i<50;++i){
            if(s[i]=='\0') break;
            if(s[i]=='A') a=1;
            else if(a&&s[i]=='I'){
                puts("YES");
                f=0; break;
            }
        }
        if(f) puts("NO");
    }
}
