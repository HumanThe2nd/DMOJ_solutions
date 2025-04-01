/*
ECOO '15 R1 P1 - When You Eat Your Smarties
Author: HumanThe2nd
Date: 2025-04-01
red skittle count * 16 + (ceil every other same color divided by 7) *13
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    for(int ti=0;ti<10;ti++){
        int r=0,o=6,b=6,g=6,y=6,p=6,v=6,br=6;
        while(1){
            char s[10];
            scanf("%s",s);
            if(s[0]=='e'){
                scanf("%s %s",s,s);
                printf("%d\n",r*16+(o/7+b/7+g/7+y/7+p/7+v/7+br/7)*13);
                break;
            }
            if(s[0]=='r') r++;
            else if(s[0]=='o') o++;
            else if(s[0]=='b'&&s[1]=='l') b++;
            else if(s[0]=='g') g++;
            else if(s[0]=='y') y++;
            else if(s[0]=='p') p++;
            else if(s[0]=='v') v++;
            else br++;
        }
    }
}
