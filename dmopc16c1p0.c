/*
DMOPC '16 Contest 1 P0 - C.C. and Cheese-kun
Author: HumanThe2nd
Date: 2025-03-25
Casework
*/
#include <stdio.h>
int main() {
    int w,c;
    scanf("%d %d",&w,&c);
    if(w==3&&c>=95) puts("C.C. is absolutely satisfied with her pizza.");
    else if(w==1&&c<=50) puts("C.C. is fairly satisfied with her pizza.");
    else puts("C.C. is very satisfied with her pizza.");
}
