/*
DMPG '19 B1 - Registration
Author: Dan SHan
Date: 2025-06-27
Subtract total people from 200
*/
#include <stdio.h>
int main() {
    int n,c=200;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int ai;
        scanf("%d",&ai);
        c-=ai;
    }
    if(c<0) puts("Over maximum capacity!");
    else printf("%d\n",c);
}
