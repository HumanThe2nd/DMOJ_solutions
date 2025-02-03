/*
GFSSOC '17 J2 - Admission Average
Author: Dan Shan
Date: 2025-02-02
if (sum of marks)/6 + aif score less than minimum no
otherwise yes
*/
#include <stdio.h>
int main() {
    int avg=0,ai,aif,req;
    for(int i=0;i<6;i++) scanf("%d",&ai),avg+=ai;
    scanf("%d %d",&aif,&req);
    if(avg/6+aif>=req) puts("yes");
    else puts("no");
}
