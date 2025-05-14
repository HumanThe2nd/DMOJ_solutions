/*
DMOPC '19 Contest 5 P2 - Charlie's Crazy Conquest
Author: HumanThe2nd
Date: 2025-04-24
Ugly Casework / Implementation
1. Alternate between player & bot
2. Hard-code last bot move if dodge
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int n,h,h2,dl=-1;
    scanf("%d %d",&n,&h);
    char s[n][2];
    int d[n]; h2=h;
    for(int i=0;i<n;i++){
        scanf("%s %d",s[i],&d[i]);
    }
    for(int i=0;i<n;i++){
        char si[2];
        int di;
        scanf("%s %d",si,&di);
        // Charlie's turn
        if(s[i][0]=='A') {
            if(dl<0) h2-=d[i];
        }
        else if(dl>0) h2-=dl;
        if(h2<=0) return puts("VICTORY")*0;
        dl=-1;
        // Bot's turn
        if(si[0]=='A'){
            if(s[i][0]=='A') h-=di;
        }
        else {
            if(s[i][0]=='D') h-=d[i];
            dl=di;
        }
        if(h<=0) return puts("DEFEAT")*0;
    }
    if(dl>0) h2-=dl; // final consequence for bot
    if(h2>0)puts("TIE");
    else puts("VICTORY");
}
