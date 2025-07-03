/*
GFSSOC '14 Winter J2 - Wow much parking lot
Author: Dan Shan
Date: 2025-07-02
Track x and y coords, starting (0,0)
North: increase y by dist
South: decrease y by dist
East: increase x by dist
West: decrease x by dist
*/
#include <stdio.h>
int main() {
    int n,x=0,y=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char s[6];
        int ai;
        scanf("%s %d",s,&ai);
        if(s[0]=='N') y+=ai;
        else if(s[0]=='S') y-=ai;
        else if(s[0]=='E') x+=ai;
        else x-=ai;
    }
    printf("%d %d\n",x,y);
}
